"""
log_data.py
This script saves the incoming data on the "loadcell" topic of an MQTT broker.
The file will be saved to the location entered in the "Output Folder" field.
Use analyze_data.py to process the saved data.
"""
import threading

# Import dependencies
from paho.mqtt import client as mqtt
from configparser import ConfigParser

# Setup configparser
print("Setting up...")
config_obj = ConfigParser()
# Read "settings.ini" file
config_obj.read("../config/settings.ini")
output_folder = config_obj["General"]["output_folder"]
motor_name = config_obj["General"]["motor_name"]
host = config_obj["General"]["host"]
port = config_obj["General"]["port"]

mqtt_client = mqtt.Client("logger")

file_path = f"{output_folder}/{motor_name}.txt"
with open(file_path, "w") as force_file:
    print(f"File created at {file_path}")
    force_file.close()


def write_to_file(value: bytes):
    if value:
        with open(file_path, "a") as force_file_:  # Open the file in "append" mode
            string_val = value.decode()
            force_file_.write(f"{string_val}\n")


def on_connect(client, userdata, flags, rc):
    print("Connected!")
    client.subscribe("loadcell")


def on_message(client, userdata, message):
    # Display the received message
    print(f"Received message on topic '{message.topic}': {message.payload}")
    write_to_file(message.payload)


# Set the on_connect and on_message callbacks
mqtt_client.on_connect = on_connect
mqtt_client.on_message = on_message


def connect_to_broker():
    mqtt_client.connect(host, int(port))
    mqtt_client.loop_start()  # Start the client's network loop


connect_to_broker()

# Keep the script running to continue receiving messages
while True:
    pass
