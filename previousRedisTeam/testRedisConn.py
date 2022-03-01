import redis

try:
    conn = redis.StrictRedis(
        host='10.122.12.158',port=6379,)
    print (conn)
    conn.ping()
    print ('Connected!')
except Exception as ex:
    print ('Error:'), ex
    exit('Failed to connect, terminating.')
