
# RocketTX

Are you passionate about rockets ? Do you build them ? 
I know you are done simulating your rocket motor in **OpenRocket** and you built your own. 

But do you have any plan about how you will analyze the performance ?

RocketTX is here to help you out.

Waiting till test launch to analyze your rocket motor can be time-taking. RocketTX is a software built for **Rocket Motor Test Stand**. 



![App Screenshot](https://raw.githubusercontent.com/Raghav67816/RocketTX/main/Screenshots/1.png)

![App Screenshot](https://raw.githubusercontent.com/Raghav67816/RocketTX/main/Screenshots/2.png)


## Features

- Open-Source & Lightweight
- Real-time motor performance monitoring and graph plotting
- Easy-to-use & Minimalistic
- Post test analysis


## Installation

Currently, it is compiled for Ubuntu, compiled executable will be uploaded soon after completing other features.

Other requirements:
- Mosquitto Broker
- Mosquitto Clients
- Python 3

Python 3 comes with Ubuntu other two needs to be installed. This can be done using the following command

```bash
sudo apt install mosquitto mosquitto_clients
```

Others, can build it from source.

## Build From Source
Following are the requirements to build it from source:

- Qt Framework 6.5.3
- Qt Creator 11.0.3
- CMake 3.24.2

After that, open the **CMakeLists.txt** in Qt Creator. Make sure to adjust for packages in the file.

Once loaded, click on **Build**. After build is successfull, you should get an executable in the build folder.

If you are facing issues with building from source, feel free to reach us.


## How To Use

First, you will need a Mqtt broker configuration file. For example:
```
listener 1883 192.168.x.x
allow_anonymous true
```

You specify other options. Please refer to [Mosquitto Configuration File Reference Page](https://mosquitto.org/man/mosquitto-conf-5.html)

> **_NOTE:_**  Make sure to run your broker on **NETWORK** not **LOCALLY**. 

To determine your IP Address you can use **ifconfig** package. To get your IP using it run:
```bash
sudo apt install ifconfig
ifconfig
```

This will output something like this:
```
enp2s0: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 192.168.x.x  netmask 255.255.255.0  broadcast 192.168.0.x
        inet6 fe80::c97f:9cb0:****:****  prefixlen 64  scopeid 0x20<link>
        ether 2c:f0:5d:a5:**:**  txqueuelen 1000  (Ethernet)
        RX packets 460576  bytes 369253755 (369.2 MB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 251316  bytes 47790353 (47.7 MB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
```

It will show all the adapters connected to your machine. Make sure to note the IP of the **WIRELESS ADAPTER**. That is in this case **192.168.x.x**

Put in the config file after writing port in the listener option. This will start your broker on your network.
