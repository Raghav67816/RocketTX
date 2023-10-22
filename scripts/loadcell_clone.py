"""
log_data.py
This script is for testing purposes.
It acts like Esp8266 is sending sensor values.
"""

# Import dependencies
from time import sleep
from random import randint
import paho.mqtt.client as mqtt
from configparser import ConfigParser

# Setup configparser
print("Setting up...")
config_obj = ConfigParser()
# Read "settings.ini" file
config_obj.read("../config/settings.ini")
host = config_obj["General"]["host"]
port = config_obj["General"]["port"]

mqtt_client = mqtt.Client("Esp8266 Clone")


def on_connect(client, userdata, flags, rc):
    print("Connected!")


def on_publish(client, userdata, rc):
    print("Published")


def connect_to_broker():
    mqtt_client.on_connect = on_connect
    mqtt_client.on_publish = on_publish
    mqtt_client.connect(host, int(port))
    mqtt_client.loop_start()  # Use loop_start() to start the client's network loop


connect_to_broker()


while True:
    # Publish data every few seconds (e.g., every 5 seconds)
    mqtt_client.publish("loadcell", str(randint(0, 1000)))
    sleep(1)
