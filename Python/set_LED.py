import time  
import datetime  
import sys  
import httplib, urllib  
import json
import socket

ledStatus = 0
node_red_IP = ""
node_red_Port = "1880"

def post_to_node_red(payload):  
    headers = {"Content-type": "application/json",}
    not_connected = 1
    while (not_connected):
        try:
            conn = httplib.HTTPConnection(node_red_IP + ":" + node_red_Port)
            conn.connect()
            not_connected = 0
        except (httplib.HTTPException, socket.error) as ex:
            print "Error: %s" % ex
            time.sleep(10)  # sleep 10 seconds

    conn.request("POST", "/setLed", json.dumps(payload), headers)
    response = conn.getresponse()
    print( response.status, response.reason, json.dumps(payload), time.strftime("%c"))
    data = response.read()
    conn.close()
 
payload = payload = {"action":ledStatus}
post_to_node_red(payload)