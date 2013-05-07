v 20110115 2
C 40000 40000 0 0 0 title-B.sym
C 47700 44900 1 0 0 L293.sym
{
T 50300 47475 5 10 0 0 0 0 1
device=L293
T 50100 47700 5 10 0 1 0 6 1
refdes=U?
}
C 43800 45800 1 0 0 dc_motor-1.sym
{
T 44200 46800 5 10 0 0 0 0 1
device=DC_MOTOR
T 44300 46400 5 10 1 1 0 0 1
refdes=Left Front
}
C 45400 45800 1 0 0 dc_motor-1.sym
{
T 45800 46800 5 10 0 0 0 0 1
device=DC_MOTOR
T 45900 46400 5 10 1 1 0 0 1
refdes=Left Rear
}
C 53000 45800 1 0 0 dc_motor-1.sym
{
T 53400 46800 5 10 0 0 0 0 1
device=DC_MOTOR
T 53500 46400 5 10 1 1 0 0 1
refdes=Right Front
}
C 54500 45800 1 0 0 dc_motor-1.sym
{
T 54900 46800 5 10 0 0 0 0 1
device=DC_MOTOR
T 55000 46400 5 10 1 1 0 0 1
refdes=Right Rear
}
N 44000 45800 45600 45800 4
N 44000 46800 45600 46800 4
N 53200 46800 54700 46800 4
N 53200 45800 54700 45800 4
N 53900 45800 53900 45500 4
N 53900 45500 51500 45500 4
N 51500 45500 51500 45800 4
N 51500 45800 50400 45800 4
N 53900 46800 53900 47000 4
N 53900 47000 51500 47000 4
N 51500 47000 51500 46700 4
N 51500 46700 50400 46700 4
N 44800 46800 44800 47000 4
N 44800 47000 46500 47000 4
N 46500 47000 46500 46700 4
N 46500 46700 47700 46700 4
N 44800 45800 44800 45500 4
N 44800 45500 46500 45500 4
N 46500 45500 46500 45800 4
N 46500 45800 47700 45800 4
C 47400 49300 1 270 0 input-2.sym
{
T 48100 48700 5 10 0 0 90 8 1
device=none
T 47500 48800 5 10 1 1 90 1 1
value=Arduino D2
}
C 46800 49300 1 270 0 input-2.sym
{
T 47500 48700 5 10 0 0 90 8 1
device=none
T 46900 48800 5 10 1 1 90 1 1
value=Arduino D3
}
C 50600 49400 1 90 1 input-2.sym
{
T 49900 48800 5 10 0 0 270 2 1
device=none
T 50500 48900 5 10 1 1 270 7 1
value=Arduino D4
}
C 51100 49400 1 90 1 input-2.sym
{
T 50400 48800 5 10 0 0 270 2 1
device=none
T 51000 48900 5 10 1 1 270 7 1
value=Arduino D5
}
N 50500 48000 50500 47000 4
N 50500 47000 50400 47000 4
N 51000 48000 51000 45500 4
N 51000 45500 50400 45500 4
N 47500 47900 47500 47000 4
N 47500 47000 47700 47000 4
C 47400 43500 1 0 0 common.sym
C 50400 43500 1 0 0 common.sym
N 47700 46400 47500 46400 4
N 47500 46400 47500 43700 4
N 47700 46100 47500 46100 4
N 50400 46400 50500 46400 4
N 50500 46400 50500 43700 4
N 50400 46100 50500 46100 4
C 54900 47900 1 0 1 terminal-1.sym
{
T 54590 48650 5 10 0 0 0 6 1
device=terminal
T 54590 48500 5 10 0 0 0 6 1
footprint=CONNECTOR 1 1
T 54650 47950 5 10 1 1 0 0 1
refdes=+7,2V
}
N 50400 47300 53500 47300 4
N 53500 47300 53500 48000 4
N 53300 48000 54000 48000 4
C 53400 49400 1 90 1 input-2.sym
{
T 52700 48800 5 10 0 0 270 2 1
device=none
T 53300 48900 5 10 1 1 270 7 1
value=Arduino Vin
}
C 54900 44900 1 0 1 terminal-1.sym
{
T 54590 45650 5 10 0 0 0 6 1
device=terminal
T 54590 45500 5 10 0 0 0 6 1
footprint=CONNECTOR 1 1
T 54650 44950 5 10 1 1 0 0 1
refdes=-7,2V
}
C 53400 44500 1 0 0 common.sym
N 54000 45000 53500 45000 4
N 53500 45000 53500 44700 4
C 55400 43900 1 0 1 input-2.sym
{
T 54800 44600 5 10 0 0 180 2 1
device=none
T 54900 44000 5 10 1 1 180 7 1
value=Arduino GND
}
C 53400 43500 1 0 0 common.sym
N 54000 44000 53500 44000 4
N 53500 44000 53500 43700 4
C 52600 49400 1 90 1 input-2.sym
{
T 51900 48800 5 10 0 0 270 2 1
device=none
T 52500 48900 5 10 1 1 270 7 1
value=Arduino 5V
}
N 52500 44400 52500 48000 4
N 52500 45200 50400 45200 4
N 52500 44400 47200 44400 4
N 47200 44400 47200 47300 4
N 47200 45200 47700 45200 4
N 47200 47300 47700 47300 4
N 46900 47900 46900 45500 4
N 46900 45500 47700 45500 4
C 43800 42000 1 0 0 connector4-1.sym
{
T 45600 42900 5 10 0 0 0 0 1
device=CONNECTOR_4
T 43800 43400 5 10 1 1 0 0 1
refdes=HC-SR04
}
T 44800 43200 9 10 1 0 0 0 1
Vcc
T 44800 42900 9 10 1 0 0 0 1
Trig
T 44800 42600 9 10 1 0 0 0 1
Echo
T 44800 42300 9 10 1 0 0 0 1
Gnd
C 46400 44800 1 270 0 input-2.sym
{
T 47100 44200 5 10 0 0 90 8 1
device=none
T 46500 44300 5 10 1 1 90 1 1
value=Arduino D7
}
C 46000 44800 1 270 0 input-2.sym
{
T 46700 44200 5 10 0 0 90 8 1
device=none
T 46100 44300 5 10 1 1 90 1 1
value=Arduino D8
}
C 45600 44800 1 270 0 input-2.sym
{
T 46300 44200 5 10 0 0 90 8 1
device=none
T 45700 44300 5 10 1 1 90 1 1
value=Arduino 5V
}
C 45700 41800 1 0 0 common.sym
N 45500 42200 45800 42200 4
N 45800 42200 45800 42000 4
N 45700 43400 45700 43100 4
N 45700 43100 45500 43100 4
N 45500 42800 46100 42800 4
N 46100 42800 46100 43400 4
N 45500 42500 46500 42500 4
N 46500 42500 46500 43400 4