from tkinter import *
from tkinter import ttk
import tkinter as tk
from tkinter import messagebox
import asyncio
import random
import aioredis
from time import sleep
import aiotkinter
import time
import redis as r

# uplink parameters listed as dictionaries for usage in updating databse required bc of .xadd syntax of aioredis
cameraBtn = {
    "cameraPosY": 0, 
    "cameraPosX": 0
    }

deployPLBtn = {
    "PayloadStatus": "NONE",
    "GCSTime" : 0
}

flightModeBtn = {
    "FlightMode": "NONE"
}

groundOffsetBtn = {
    "GroundOffset": 0.0
}

uplinkDroneParams = ["uplinkDroneParams"]


# create tasks for safe coroutine when a button is clicked
def do_tasks(args, args1):
    task = asyncio.ensure_future(checkBTNS(args, args1))
    
async def checkBTNS(typeBtn, value):
    conn = r.StrictRedis(host = '10.122.12.158', port =6379)
    redis = conn
    print("Connected to pi4 server!")
    #redis = await aioredis.create_redis_pool('10.122.12.158', port=6379))
    
    # the returned list from redis is len 4 so each stream entry call is in the same order Flight Mode[0], Deploy PL[1], Camera[2], GndOffset[3] see conversion in each fnct    
    async def gndOffsetXRevRange():
        # get most up to date values (current)
        gndOffsetListTmp = await redis.xrevrange('uplinkDroneParams', start='+', stop='-', count=4) # get the last(latest) stream: ID, fields, and their values
        #print(type(gndOffsetListTmp)) = 'list' but it's a bad list so we have to convert so it's usable
        #print(len(gndOffsetListTmp))  = len = 4
        gndOffsetStrTmp = str(gndOffsetListTmp[3]) #convert it into a str that's usable from a list, each param passed is a different number in list
        gndOffsetIDStr = gndOffsetStrTmp[3:18] # get the latest ID always between 3:18
        gndOffsetStr = gndOffsetStrTmp.partition("'GroundOffset', b'")[2].partition("')")[0] # https://stackoverflow.com/questions/34834258/python-most-elegant-way-to-extract-a-substring-being-given-left-and-right-bor
        print("event ID: " + gndOffsetIDStr)
        print("GroundOffset: " + gndOffsetStr)
 
        #print(type(gndOffsetStr)) = 'str'
        #print(gndOffsetStrTmp) = (b'1617446611625-0', OrderedDict([(b'cameraPosY', b'0'), (b'cameraPosX', b'71')])) this is what the format looks like 
        
        groundOffsetBtn.update({"GroundOffset": gndOffsetStr}) # update groundOffsetBtn dictionary w/ PayloadStatus from database (current)
                
    async def cameraXRevRange():
        # get most up to date values (current)
        cameraPosListTmp = await redis.xrevrange('uplinkDroneParams', start='+', stop='-', count=4) # get the last(latest) stream: ID, fields, and their values
        #print(type(cameraPosListTmp)) = 'list' but it's a bad list so we have to convert so it's usable
        #print(len(cameraPosListTmp))  = len = 1
        cameraPosStrTmp = str(cameraPosListTmp[2]) #convert it into a str that's usable from a list, each param passed is a different number in list
        cameraPosIDStr = cameraPosStrTmp[3:18] # get the latest ID always between 3:18
        cameraPosYStr = cameraPosStrTmp.partition("'cameraPosY', b'")[2].partition("')")[0] # https://stackoverflow.com/questions/34834258/python-most-elegant-way-to-extract-a-substring-being-given-left-and-right-bor
        cameraPosXStr = cameraPosStrTmp.partition("'cameraPosX', b'")[2].partition("')")[0] # https://stackoverflow.com/questions/34834258/python-most-elegant-way-to-extract-a-substring-being-given-left-and-right-bor
        ##deployPLStr = cameraPosStrTmp.partition("'PayloadStatus', b'")[2].partition("')")[0] # https://stackoverflow.com/questions/34834258/python-most-elegant-way-to-extract-a-substring-being-given-left-and-right-bor
        #getting both PosY and PosX bc otherwise it will reset the other, both values must be gotten and updated during all pulls of up,down,left,right          
        print("event ID: " + cameraPosIDStr)
        print("camera Pos Y: " + cameraPosYStr)
        print("camera Pos X: " + cameraPosXStr)
        ##print("PayloadStatus : " + deployPLStr)
        #print(type(cameraPosIDSTR)) = 'str'
        #print(cameraPosStrTmp) = (b'1617446611625-0', OrderedDict([(b'cameraPosY', b'0'), (b'cameraPosX', b'71')])) this is what the format looks like 
       
        #update both values to dict bc of comment above      
        cameraBtn.update({"cameraPosY": int(cameraPosYStr)}) # update cameraBtn dictionary w/ cameraPosY from database (current)
        cameraBtn.update({"cameraPosX": int(cameraPosXStr)}) # update cameraBtn dictionary w/ cameraPosX from database (current)
    
    async def deployPLXRevRange():
        # get most up to date values (current)
        deployPLListTmp = await redis.xrevrange('uplinkDroneParams', start='+', stop='-', count=4) # get the last(latest) stream: ID, fields, and their values
        #print(type(deployPLListTmp)) = 'list' but it's a bad list so we have to convert so it's usable
        #print(len(deployPLListTmp))  = len = 1
        deployPLStrTmp = str(deployPLListTmp[1]) #convert it into a str that's usable from a list, each param passed is a different number in list
        deployPLIDStr = deployPLStrTmp[3:18] # get the latest ID always between 3:18
        deployPLStr = deployPLStrTmp.partition("'PayloadStatus', b'")[2].partition("')")[0] # https://stackoverflow.com/questions/34834258/python-most-elegant-way-to-extract-a-substring-being-given-left-and-right-bor
        deployTIMEStr = deployPLStrTmp.partition("'GCSTime', b'")[2].partition("')")[0] # https://stackoverflow.com/questions/34834258/python-most-elegant-way-to-extract-a-substring-being-given-left-and-right-bor

        print("event ID: " + deployPLIDStr)
        print("PayloadStatus : " + deployPLStr)
        print("GCSTime : " + deployTIMEStr)
        ##print("camera Pos Y: " + cameraPosYStr)
        ##print("camera Pos X: " + cameraPosXStr)
        
        #print(type(deployPLIDStr)) = 'str'
        #print(deployPLStrTmp) = (b'1617446611625-0', OrderedDict([(b'cameraPosY', b'0'), (b'cameraPosX', b'71')])) this is what the format looks like 
        deployPLBtn.update({"PayloadStatus": deployPLStr}) # update deployPLBtn dictionary w/ PayloadStatus from database (current)

    
    
    async def flightModeXRevRange():
        # get most up to date values (current)
        flightModeListTmp = await redis.xrevrange('uplinkDroneParams', start='+', stop='-', count=4) # get the last(latest) stream: ID, fields, and their values
        #print(type(flightModeListTmp)) = 'list' but it's a bad list so we have to convert so it's usable
        #print(len(flightModeListTmp))  = len = 1
        flightModeStrTmp = str(flightModeListTmp[0]) #convert it into a str that's usable from a list, each param passed is a different number in list
        flightModeIDStr = flightModeStrTmp[3:18] # get the latest ID always between 3:18
        flightModeStr = flightModeStrTmp.partition("'FlightMode', b'")[2].partition("')")[0] # https://stackoverflow.com/questions/34834258/python-most-elegant-way-to-extract-a-substring-being-given-left-and-right-bor
        print("event ID: " + flightModeIDStr)
        print("FlightMode: " + flightModeStr)
        
        #print(type(flightModeIDStr)) = 'str'
        #print(flightModeStrTmp) = (b'1617446611625-0', OrderedDict([(b'cameraPosY', b'0'), (b'cameraPosX', b'71')])) this is what the format looks like 
        
        flightModeBtn.update({"FlightMode": flightModeStr}) # update flightModeBtn dictionary w/ PayloadStatus from database (current)
    
                
    if typeBtn == "flightMode":
        
        # update all local dictionaries to databse values, as to not overwrite anything w/ default values
        await deployPLXRevRange()
        await cameraXRevRange()
        await flightModeXRevRange()
        await gndOffsetXRevRange()        

        if value == "Performance":
            flightModeDictTemp = {"FlightMode" : "Performance"}
            flightModeBtn.update(flightModeDictTemp) # update flightMode value to Performance
            xaddgndOffset = await redis.xadd('uplinkDroneParams', groundOffsetBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using groundOffsetBtn dictionary
            xaddCamera = await redis.xadd('uplinkDroneParams', cameraBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using cameraBtn dictionary
            xaddDeployPL = await redis.xadd('uplinkDroneParams', deployPLBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using deployPLBtn dictionary
            xaddflightMode = await redis.xadd('uplinkDroneParams', flightModeBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using flightModeBtn dictionary
                
        elif value == "Battery-Saver":
            flightModeDictTemp = {"FlightMode" : "Battery"}
            flightModeBtn.update(flightModeDictTemp) # update flightMode value to Battery
            xaddgndOffset = await redis.xadd('uplinkDroneParams', groundOffsetBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using groundOffsetBtn dictionary
            xaddCamera = await redis.xadd('uplinkDroneParams', cameraBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using cameraBtn dictionary
            xaddDeployPL = await redis.xadd('uplinkDroneParams', deployPLBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using deployPLBtn dictionary
            xaddflightMode = await redis.xadd('uplinkDroneParams', flightModeBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using flightModeBtn dictionary
        
        elif value == "Quiet-Mode":
            flightModeDictTemp = {"FlightMode" : "Quiet-Mode"}
            flightModeBtn.update(flightModeDictTemp) # update flightMode value to Quiet-Mode
            xaddgndOffset = await redis.xadd('uplinkDroneParams', groundOffsetBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using groundOffsetBtn dictionary
            xaddCamera = await redis.xadd('uplinkDroneParams', cameraBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using cameraBtn dictionary
            xaddDeployPL = await redis.xadd('uplinkDroneParams', deployPLBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using deployPLBtn dictionary
            xaddflightMode = await redis.xadd('uplinkDroneParams', flightModeBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using flightModeBtn dictionary
            
        elif value == "Stability":
            flightModeDictTemp = {"FlightMode" : "Stability"}
            flightModeBtn.update(flightModeDictTemp) # update flightMode value to Stability
            xaddgndOffset = await redis.xadd('uplinkDroneParams', groundOffsetBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using groundOffsetBtn dictionary
            xaddCamera = await redis.xadd('uplinkDroneParams', cameraBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using cameraBtn dictionary
            xaddDeployPL = await redis.xadd('uplinkDroneParams', deployPLBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using deployPLBtn dictionary
            xaddflightMode = await redis.xadd('uplinkDroneParams', flightModeBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using flightModeBtn dictionary
            
        else:
            print("Lost in flight mode button, bad value -value")
        
    elif typeBtn == "deployPL":
        
        # update all local dictionaries to databse values, as to not overwrite anything w/ default values
        await deployPLXRevRange()
        await cameraXRevRange()
        await flightModeXRevRange()
        await gndOffsetXRevRange()  
        
        deployPLListTmp1 = [*deployPLBtn.values()]  # unpack dict values into a list, then get the value for PayloadStatus [0] 
                                            # https://stackoverflow.com/questions/16228248/how-can-i-get-list-of-values-from-dict
        deployPLStrTmp1 = deployPLListTmp1[0]           # PayloadStatus value stored here
        
        # time in nanoseconds since epoch
        time_nanosec = time.time_ns()                      # https://www.geeksforgeeks.org/python-time-time_ns-method/
        deployPLBtn.update({"GCSTime": int(time_nanosec)}) # update cameraBtn dictionary w/ cameraPosX from database (current)
        
        if value == "RESETPL":
            # reset button will add this parameter to database regardless of anything
            resetPLDictTemp = {"PayloadStatus" : "CARRYING"}
            deployPLBtn.update(resetPLDictTemp) # update PayloadStatus to CARRYING
            xaddgndOffset = await redis.xadd('uplinkDroneParams', groundOffsetBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using groundOffsetBtn dictionary
            xaddCamera = await redis.xadd('uplinkDroneParams', cameraBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using cameraBtn dictionary
            xaddResetPL = await redis.xadd('uplinkDroneParams', deployPLBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using deployPLBtn dictionary
            xaddflightMode = await redis.xadd('uplinkDroneParams', flightModeBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using flightModeBtn dictionary
                       
                 
        elif value == "DEPLOYPL":    
            if deployPLStrTmp1 == "CARRYING":  
                deployPLDictTemp = {"PayloadStatus" : "DROPPED"}
                deployPLBtn.update(deployPLDictTemp) # update PayloadStatus to DROPPED
                xaddgndOffset = await redis.xadd('uplinkDroneParams', groundOffsetBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using groundOffsetBtn dictionary
                xaddCamera = await redis.xadd('uplinkDroneParams', cameraBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using cameraBtn dictionary
                xaddDeployPL = await redis.xadd('uplinkDroneParams', deployPLBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using deployPLBtn dictionary
                xaddflightMode = await redis.xadd('uplinkDroneParams', flightModeBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using flightModeBtn dictionary
                
            elif deployPLStrTmp1 == "DROPPED":
                print("Payload status: DROPPED already")
            else:
                print("Payload unknown status")
        else:
            print("Lost at deployPL bad value")
                        
    elif typeBtn == "camera":
        
        # update all local dictionaries to databse values, as to not overwrite anything w/ default values
        await deployPLXRevRange()
        await cameraXRevRange()
        await flightModeXRevRange()
        await gndOffsetXRevRange()        
        
        cameraListTmp = [*cameraBtn.values()]  # unpack dict values into a list, then get the value for cameraPosX [1] (cameraPosY is [0] as reference)
                                            # https://stackoverflow.com/questions/16228248/how-can-i-get-list-of-values-from-dict
        cameraYIntTmp = cameraListTmp[0]           # cameraPosY value stored here
        cameraXIntTmp = cameraListTmp[1]           # cameraPosX value stored here

        if value == "Left":
            if cameraXIntTmp > -180:  
                cameraXDictTemp = {"cameraPosX" : cameraXIntTmp-10}
                cameraBtn.update(cameraXDictTemp) # update cameraPosX value +10
                xaddgndOffset = await redis.xadd('uplinkDroneParams', groundOffsetBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using groundOffsetBtn dictionary            
                xaddCamera = await redis.xadd('uplinkDroneParams', cameraBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using cameraBtn dictionary
                xaddDeployPL = await redis.xadd('uplinkDroneParams', deployPLBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using deployPLBtn dictionary
                xaddflightMode = await redis.xadd('uplinkDroneParams', flightModeBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using flightModeBtn dictionary
            else:
                print("X IS AT MAX (-)")
                
        elif value == "Right":
            if cameraXIntTmp < 180:  
                cameraXDictTemp = {"cameraPosX" : cameraXIntTmp+10}
                cameraBtn.update(cameraXDictTemp) # update cameraPosX value +10
                xaddgndOffset = await redis.xadd('uplinkDroneParams', groundOffsetBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using groundOffsetBtn dictionary
                xaddCamera = await redis.xadd('uplinkDroneParams', cameraBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using cameraBtn dictionary
                xaddDeployPL = await redis.xadd('uplinkDroneParams', deployPLBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using deployPLBtn dictionary
                xaddflightMode = await redis.xadd('uplinkDroneParams', flightModeBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using flightModeBtn dictionary
            else:
                print("X IS AT MAX (+)")
        
        elif value == "Up":
            if cameraYIntTmp < 180:  
                cameraYDictTemp = {"cameraPosY" : cameraYIntTmp+10}
                cameraBtn.update(cameraYDictTemp) # update cameraPosY value +10
                xaddgndOffset = await redis.xadd('uplinkDroneParams', groundOffsetBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using groundOffsetBtn dictionary
                xaddCamera = await redis.xadd('uplinkDroneParams', cameraBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using cameraBtn dictionary
                xaddDeployPL = await redis.xadd('uplinkDroneParams', deployPLBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using deployPLBtn dictionary
                xaddflightMode = await redis.xadd('uplinkDroneParams', flightModeBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using flightModeBtn dictionary
            else:
                print("Y IS AT MAX (+)")
            
        elif value == "Down":
            if cameraYIntTmp > -180:  
                cameraYDictTemp = {"cameraPosY" : cameraYIntTmp-10}
                cameraBtn.update(cameraYDictTemp) # update cameraPosY value +10
                xaddgndOffset = await redis.xadd('uplinkDroneParams', groundOffsetBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using groundOffsetBtn dictionary
                xaddCamera = await redis.xadd('uplinkDroneParams', cameraBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using cameraBtn dictionary
                xaddDeployPL = await redis.xadd('uplinkDroneParams', deployPLBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using deployPLBtn dictionary
                xaddflightMode = await redis.xadd('uplinkDroneParams', flightModeBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using flightModeBtn dictionary                
            else:
                print("Y IS AT MIN (-)")
            
        else:
            print("Lost in camera button, bad value -value")

    elif typeBtn == "gndoffsetsubmit":
        
        # update all local dictionaries to databse values, as to not overwrite anything w/ default values
        await deployPLXRevRange()
        await cameraXRevRange()
        await flightModeXRevRange()
        await gndOffsetXRevRange()        
        
        gndOffsetListTmp1 = [*groundOffsetBtn.values()]  # unpack dict values into a list, then get the value for GroundOffset [0] 
                                                       # https://stackoverflow.com/questions/16228248/how-can-i-get-list-of-values-from-dict
        gndOffsetFltTmp = gndOffsetListTmp1[0]        # GroundOffset value stored here

        #print("Groundoffset test val: " + str(gndOffsetFltTmp))
        if 0.1 <= value <= 100.0:
            gndOffsetDictTemp = {"GroundOffset" : value}
            groundOffsetBtn.update(gndOffsetDictTemp) # update flightMode value to Performance
            xaddgndOffset = await redis.xadd('uplinkDroneParams', groundOffsetBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using cameraBtn dictionary            
            xaddCamera = await redis.xadd('uplinkDroneParams', cameraBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using cameraBtn dictionary
            xaddDeployPL = await redis.xadd('uplinkDroneParams', deployPLBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using deployPLBtn dictionary
            xaddflightMode = await redis.xadd('uplinkDroneParams', flightModeBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using flightModeBtn dictionary
                
        elif value == 0.0:
            gndOffsetDictTemp = {"GroundOffset" : value}
            groundOffsetBtn.update(gndOffsetDictTemp) # update flightMode value to Performance
            xaddgndOffset = await redis.xadd('uplinkDroneParams', groundOffsetBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using cameraBtn dictionary            
            xaddCamera = await redis.xadd('uplinkDroneParams', cameraBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using cameraBtn dictionary
            xaddDeployPL = await redis.xadd('uplinkDroneParams', deployPLBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using deployPLBtn dictionary
            xaddflightMode = await redis.xadd('uplinkDroneParams', flightModeBtn, message_id='*', max_len=None, exact_len=False)  #add it to the database using flightModeBtn dictionary
        
        elif value > 100.0:
            print("GroundOffset invalid MAX (100.0m)")
                        
        elif value < 0.0:
            print("GroundOffset invalid MIN (0.0m)")
                        
        else:
            print("Lost in Ground Offset button, bad value (not float?) -value")

    ###############************IMPLEMENT THE ACKNOWLEDGE FUNCTION WHERE APPROPIATE THAT WE ARE ACTUALLY ACKNOWLEDGING WE ARE TAKING LATEST VALUE    
                 
    else:
        print("Invalid argument") # some button is bad
    
    # use below if there is no group called simpleGCS for uplinkDroneParams stream 
    # await redis.xgroup_create('uplinkDroneParams', 'simpleGCS', latest_id='$', mkstream=True)
    groups_list = await redis.xinfo_groups('uplinkDroneParams')
    print(groups_list)
    # consumer_list = await redis.xinfo_consumers('uplinkDroneParams','simpleGCS')
    # print(consumer_list)


if __name__ == '__main__':
    asyncio.set_event_loop_policy(aiotkinter.TkinterEventLoopPolicy())
    loop = asyncio.get_event_loop()
    root = Tk()
    root.title('Simple Ground Control Station (GCS)')
    
    #------Initialize items--------
    #Frames/borders
    content = tk.Frame(root)
    frame = tk.Frame(content, borderwidth=5, relief="ridge", width=600, height=300)
    #Labels/text
    cameralbl = tk.Label(content, text="Camera Position")
    flightMlbl = tk.Label(content, text="Flight Mode Selection")
    gndOffsetlbl = tk.Label(content, text="Ground Offset (0.0) (m)")
    deployPLlbl = tk.Label(content, text="DEPLOY PAYLOAD")

    #Deploy Payload button
    deployPayload_btn = Button(content, text="DEPLOY", command=lambda:do_tasks("deployPL", "DEPLOYPL"))
    resetPayload_btn = Button(content, text="RESET PL", command=lambda:do_tasks("deployPL", "RESETPL"))

    #Camera Buttons
    left_btn = tk.Button(content, text="Left", command=lambda:do_tasks("camera", "Left"))
    right_btn = tk.Button(content, text="Right", command=lambda:do_tasks("camera", "Right"))
    up_btn = tk.Button(content, text="Up", command=lambda:do_tasks("camera", "Up"))
    down_btn = tk.Button(content, text="Down", command=lambda:do_tasks("camera", "Down"))

    #Drop down Flight modes
    clicked = StringVar(content)
    dropDown = tk.OptionMenu(content, clicked, "Performance", "Battery-Saver", "Quiet-Mode", "Stability")
    #Submit button Flight modes
    submit_button = Button(content, text="Submit", command=lambda:do_tasks("flightMode", clicked.get()))

    #Ground offset entry
    gndOffsetEntry = tk.Entry(content, width=5)
    gndOffsetSubmit_btn = Button(content, text="Submit", command=lambda:do_tasks( "gndoffsetsubmit", float(gndOffsetEntry.get())))
    #------Initialize items--------
    #------Positions--------
    content.grid(column=0, row=0)
    frame.grid(column=3, row=3, columnspan=3, rowspan=4)

    #Deploy / Reset Payload pos 
    deployPLlbl.grid(column=0, row=3)
    deployPayload_btn.grid(column=0, row=4)
    resetPayload_btn.grid(column=0, row=5)

    #ground offset pos
    gndOffsetlbl.grid(column=0, row=0, columnspan=1)
    gndOffsetEntry.grid(column=0, row=1, columnspan=1)
    gndOffsetSubmit_btn.grid(column=0, row=2)

    #flight mode pos
    flightMlbl.grid(column=4, row=0, columnspan=1)
    dropDown.grid(column=4, row=1)
    submit_button.grid(column=4, row=2)

    #camera pos
    cameralbl.grid(column=4, row=3, columnspan=1)
    left_btn.grid(column=3, row=5)
    right_btn.grid(column=5, row=5)
    up_btn.grid(column=4, row=4)
    down_btn.grid(column=4, row=6)
    #------Positions--------
    
    
    #buttonT = Button(master=root, text='Asyncio Tasks', command=do_tasks)
    #buttonT.pack()
    #buttonX = Button(master=root, text='Freezed???', command=do_freezed)
    #buttonX.pack()
    loop.run_forever()
