## Check MAC Address before the main program.


* By default, the "main" program cannot pass the MAC address check.
* To add an authorized machine, use "addSalt.exe" to generate the salt-MAC-address.
* Manually add the salt-MAC-address to GLOBAL_machineMacAddr in "main.cpp"
* Then, the "main" program can pass the MAC address check.


One may need to modify the device name "enp4s0f0" in "main.cpp"
It may be "eth0" or whatever the name is shown in the beginning of "ifconfig".