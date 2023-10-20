"""
log_data.py
This scripts saves the incoming data on "loadcell" topic of mqtt broker
File will be saved to the location entered in the "Output Folder" field.
Use analyze_data.py to get other values.
"""

# Import dependencies
from paho.mqtt import client
from configparser import ConfigParser

# Setup configparser
print("Setting up...")
config_obj = ConfigParser()
# Read "settings.ini" file
config_obj.read("/media/raghav/Sector 16/TestStandSoftware/config/settings.ini")
output_folder = config_obj["General"]["output_folder"]
motor_name = config_obj["General"]["motor_name"]
host = config_obj["General"]["host"]
port = config_obj["General"]["port"]

with open(f"{output_folder}/{motor_name}.txt", "w") as force_file:
    print("file made")
    force_file.close()

def on_connect():
    print("Connected!")

def connect_to_broker():
    mqtt_client = client.Client("logger")
    mqtt_client.connect(host, int(port))
    mqtt_client.loop_forever()

connect_to_broker()
