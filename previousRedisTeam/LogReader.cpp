#include "SMUC_Logger.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <hiredis/hiredis.h> //https://github.com/redis/hiredis

// Makefile tutorial: https://www.youtube.com/watch?v=_r7i5X0rXJk

#ifdef DBG
#define DBGPRT(a) printf a
#else
#define DBGPRT(a)
#endif
// this goes in the make file 40:00

//#define DBGPRT(a) // this gets rid of all the debug marco calls DBGPRT
//DBGPRT((""%s:%d $d $d\n", __FILE__, __LINE__, i, x)); // with i and x as variables

// how to call DBGPRT
//DBGPRT((""%s:%d $d $d\n", __FILE__, __LINE__, 3, 4));

extern void myusleep(long t);




using namespace std;


int main(int argc, char const *argv[]) {

  RemoteControls controls;
	InertialData inertial;
	BarometerData barometer;
	GPSData gps;
	ControlData controlData;
	Motors motors;

  unsigned int j, isunix = 0;  
  redisContext *c;
  redisReply *reply;
  const char *hostname = (argc > 1) ? argv[1] : "127.0.0.1";
  
  // redis connection setup
  if (argc > 2) {
    if (*argv[2] == 'u' || *argv[2] == 'U') {
      isunix = 1;
      /* in this case, host is the path to the unix socket */
      printf("Will connect to unix socket @%s\n", hostname);
    }
  }

  int port = (argc > 2) ? atoi(argv[2]) : 6379;
  struct timeval timeout = { 1, 500000 }; // 1.5 seconds

  if (isunix) {
    c = redisConnectUnixWithTimeout(hostname, timeout);
  } else {
    c = redisConnectWithTimeout(hostname, port, timeout);
  }
  if (c == NULL || c->err) {
    if (c) {
      printf("Connection error: %s\n", c->errstr);
      redisFree(c);
    } else {
      printf("Connection error: can't allocate redis context\n");
    }
    exit(1);
  }
  
  /* PING server */
  reply = (redisReply*)redisCommand(c,"PING"); // https://stackoverflow.com/questions/15937309/errorpe513-a-value-of-type-void-cannot-be-assigned-to-an-entity-of-type
  printf("PING: %s\n", reply->str);
  freeReplyObject(reply);    
  





  int32_t type; // for defined types in SMUC_Logger.h
  double runTime = 0;   // used to as the timeStamp
  double prevrunTime; // previous runTime stored
  double slowdownMult = 5000; //* 100000; // multiplier for sleep



  FILE *fp;
  fp = fopen("log", "rb"); // read binary mode for file "log"

  while(!fp){
    perror("Error opening file\n");
    exit(EXIT_FAILURE);
  }

 // printf("%d %d %d\n", sizeof(int), sizeof(float), sizeof(double));
 // exit(0);


  while(!feof(fp)) {

    fread(&type,sizeof(type),1,fp);



    switch(type) {

      case SYNC:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
  			fread(&type,sizeof(type),1,fp);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        break;


      case ROLL_REF:
        prevrunTime = runTime;

        fread(&runTime,sizeof(runTime),1,fp);
  			fread(&controls.roll,sizeof(controls.roll),1,fp);
        printf("hmset RemoteControls roll %lf \n", controls.roll );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("slept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;

#if 1

      case PITCH_REF:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
        fread(&controls.pitch,sizeof(controls.pitch),1,fp);
        printf("hmset RemoteControls roll %lf  \n", controls.pitch );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;

      case YAW_REF:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
        fread(&controls.yaw,sizeof(controls.yaw),1,fp);
        printf("hmset RemoteControls roll %lf  \n", controls.yaw );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;

      case THROTTLE_REF:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
        fread(&controls.throttle,sizeof(controls.throttle),1,fp);
        printf("hmset RemoteControls roll %lf  \n", controls.throttle );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;


      case INERTIAL_ROLL:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&inertial.roll,sizeof(inertial.roll),1,fp);
        printf("hmset inertial.roll roll %lf  \n", inertial.roll );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case INERTIAL_PITCH:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&inertial.pitch,sizeof(inertial.pitch),1,fp);
        printf("hmset inertial.pitch roll %lf  \n", inertial.pitch );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case INERTIAL_YAW:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&inertial.gZ,sizeof(inertial.gZ),1,fp);
        printf("hmset inertial.gZ roll %lf  \n", inertial.gZ );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case ACCEL_X:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&inertial.aX,sizeof(inertial.aX),1,fp);
        printf("hmset inertial.aX roll %lf  \n", inertial.aX );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case ACCEL_Y:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&inertial.aY,sizeof(inertial.aY),1,fp);
        printf("hmset inertial.aY roll %lf  \n", inertial.aY );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case ACCEL_Z:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&inertial.aZ,sizeof(inertial.aZ),1,fp);
        printf("hmset inertial.aZ roll %lf  \n", inertial.aZ );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case GYRO_X:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&inertial.gX,sizeof(inertial.gX),1,fp);
        printf("hmset inertial.gX roll %lf  \n", inertial.gX );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case GYRO_Y:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&inertial.gY,sizeof(inertial.gY),1,fp);
        printf("hmset inertial.gY roll %lf  \n", inertial.gY );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case GYRO_Z:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&inertial.gZ,sizeof(inertial.gZ),1,fp);
        printf("hmset inertial.gZ roll %lf  \n", inertial.gZ );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case MAG_X:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&inertial.mX,sizeof(inertial.mX),1,fp);
        printf("hmset inertial.mX roll %lf  \n", inertial.mX );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case MAG_Y:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&inertial.mY,sizeof(inertial.mY),1,fp);
        printf("hmset inertial.mY roll %lf  \n", inertial.mY );
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case MAG_Z:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&inertial.mZ,sizeof(inertial.mZ),1,fp);
        printf("hmset inertial.mZ roll %lf  \n", inertial.mZ );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;


      case BAROMETER_PRESSURE:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&barometer.pressure,sizeof(barometer.pressure),1,fp);
        printf("hmset barometer.pressure roll %lf  \n", barometer.pressure );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case BAROMETER_TEMPERATURE:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&barometer.temperature,sizeof(barometer.temperature),1,fp);
        printf("hmset barometer.temperature roll %lf  \n", barometer.temperature );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case BAROMETER_ALTITUDE:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&barometer.altitude,sizeof(barometer.altitude),1,fp);
        printf("hmset barometer.altitude roll %lf  \n", barometer.altitude );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;


/*      case GPS_ITOW:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);

        printf("hmset RemoteControls roll %lf  \n", controls.throttle );
        myusleep( (runTime - prevrunTime) * slowdownMult );
        break;
      case GPS_LAT:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);

        printf("hmset RemoteControls roll %lf  \n", controls.throttle );
        myusleep( (runTime - prevrunTime) * slowdownMult );
        break;
      case GPS_LON:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);

        printf("hmset RemoteControls roll %lf  \n", controls.throttle );
        myusleep( (runTime - prevrunTime) * slowdownMult );
        break;
*/

      case GPS_HEIGHT:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&gps.height,sizeof(gps.height),1,fp);
        printf("hmset gps.height roll %lf  \n", gps.height );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case GPS_H_ACCURACY:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&gps.hAccuracy,sizeof(gps.hAccuracy),1,fp);
        printf("hmset gps.hAccuracy roll %lf  \n", gps.hAccuracy );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case GPS_V_ACCURACY:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&gps.vAccuracy,sizeof(gps.vAccuracy),1,fp);
        printf("hmset gps.vAccuracy roll %lf  \n", gps.vAccuracy );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case GPS_VEL_NORTH:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&gps.velNorth,sizeof(gps.velNorth),1,fp);
        printf("hmset gps.velNorth roll %lf  \n", gps.velNorth );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case GPS_VEL_EAST:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&gps.velEast,sizeof(gps.velEast),1,fp);
        printf("hmset gps.velEast roll %lf  \n", gps.velEast );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case GPS_VEL_DOWN:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&gps.velDown,sizeof(gps.velDown),1,fp);
        printf("hmset gps.velDown roll %lf  \n", gps.velDown );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case GPS_GROUND_SPEED:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&gps.groundSpeed,sizeof(gps.groundSpeed),1,fp);
        printf("hmset gps.groundSpeed roll %lf  \n", gps.groundSpeed );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case GPS_HEADING:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&gps.heading,sizeof(gps.heading),1,fp);
        printf("hmset gps.heading roll %lf  \n", gps.heading );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case GPS_SPEED_ACCURACY:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&gps.speedAccuracy,sizeof(gps.speedAccuracy),1,fp);
        printf("hmset gps.speedAccuracy roll %lf  \n", gps.speedAccuracy );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case GPS_HEIGHT_ELLIPSOID:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&gps.heightEllipsoid,sizeof(gps.heightEllipsoid),1,fp);
        printf("hmset gps.heightEllipsoid roll %lf  \n", gps.heightEllipsoid );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case GPS_SPEED_3D:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&gps.speed3D,sizeof(gps.speed3D),1,fp);
        printf("hmset gps.speed3D roll %lf  \n", gps.speed3D );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case GPS_STATUS:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&gps.gpsStatus,sizeof(gps.gpsStatus),1,fp);
        printf("hmset gps.gpsStatus roll %d  \n", gps.gpsStatus );
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;


  /* // it's under MSG_CONTROL_DATA but has the same type names, will need to change type names

      case ROLL_REF:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&controlData.rollRef,sizeof(controlData.rollRef),1,fp);
        printf("hmset controlData.rollRef roll %lf  \n", controlData.rollRef );
        myusleep( (runTime - prevrunTime) * slowdownMult );
        break;
      case PITCH_REF:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&controlData.pitchRef,sizeof(controlData.pitchRef),1,fp);
        printf("hmset controlData.pitchRef roll %lf  \n", controlData.pitchRef );
        myusleep( (runTime - prevrunTime) * slowdownMult );
        break;
      case YAW_REF:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&controlData.yawRef,sizeof(controlData.yawRef );
        myusleep( (runTime - prevrunTime) * slowdownMult );
        break;
      case THROTTLE_REF:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&controls.throttle,sizeof(controls.throttle),1,fp);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        break;
      case INERTIAL_ROLL:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&inertial.roll,sizeof(inertial.roll),1,fp);
        printf("hmset controlData.rollRef roll %lf  \n", controlData.rollRef );
        myusleep( (runTime - prevrunTime) * slowdownMult );
        break;
      case INERTIAL_PITCH:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&inertial.pitch,sizeof(inertial.pitch),1,fp);
        printf("hmset controlData.pitchRef roll %lf  \n", controlData.pitchRef );
        myusleep( (runTime - prevrunTime) * slowdownMult );
        break;
      case INERTIAL_YAW:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&inertial.gZ,sizeof(inertial.gZ),1,fp);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        break;
*/
      case MOTOR_FL:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&motors.FL,sizeof(motors.FL),1,fp);
        printf("hmset motors.FL roll %lf  \n", motors.FL );   
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);     
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case MOTOR_BL:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&motors.BL,sizeof(motors.BL),1,fp);
        printf("hmset motors.BL roll %lf  \n", motors.BL );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case MOTOR_FR:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&motors.FR,sizeof(motors.FR),1,fp);
        printf("hmset motors.FR roll %lf  \n", motors.FR );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;
      case MOTOR_BR:
        prevrunTime = runTime;
        fread(&runTime,sizeof(runTime),1,fp);
				fread(&motors.BR,sizeof(motors.BR),1,fp);
        printf("hmset motors.BR roll %lf  \n", motors.BR );
        printf("runtime value = %lf\n" , runTime);
        printf("prevruntime value = %lf\n" , prevrunTime);
        myusleep( (runTime - prevrunTime) * slowdownMult );
        printf("sleept for t = %lf\n" , ((runTime - prevrunTime) * slowdownMult ));
        break;

#endif

      default:
      printf("Message recieved not valid. logger Type %d\n", type);
      break;




    }
  }


  fcloseall();

  return 0;

}


void myusleep(long t) {

  if(t <= 0) return;

  if(t > 1000000) t=1000000; 
  usleep(t);

}