#!/bin/bash
sudo chmod 777 /dev/ttyUSB0
sudo cat /dev/ttyUSB0> Sensor.txt <<EOF
exit $?
EOF

