#!/bin/sh

printf ">>Formato de salida: csv\n"

./main -fmt csv -out output.csv -in examples/test_file_20.csv -ti 1320498000 -tf 1320498046
./main -fmt csv -out output.csv -in examples/test_file_2k.csv -ti 1320498000 -tf 1325499000
./main -fmt csv -out output.csv -in examples/test_file_50.csv -ti 1320498000 -tf 1320498049
./main -fmt csv -out output.csv -in examples/test_file_500.csv -ti 1320498000 -tf 1320529000
./main -fmt csv -out output.csv -in examples/test_file_5k.csv -ti 1320498000 -tf 1320529000
./main -fmt csv -out output.csv -in examples/test_file_50k.csv -ti 1320498000 -tf 1420529000
./main -fmt csv -out output.csv -in examples/test_file_500k.csv -ti 1320498000 -tf 1420529000


printf "\n>>Formato de salida: xml\n"
./main -fmt xml -out output.xml -in examples/test_file_50.csv -ti 1320498000 -tf 1320498049
./main -fmt xml -out output.xml -in examples/test_file_5k.csv -ti 1320498000 -tf 1360498049
./main -fmt xml -out output.xml -in examples/test_file_5m.csv -ti 1320498000 -tf 1360498049
./main -fmt xml -out output.xml -in -ti 1320498000 -tf 1360498049
./main -out output.xml -fmt xml -in examples/test_file_5k.csv -ti 1320498000 -tf 1360498049
./main -out output.xml -fmt xml -in examples/test_file_5k.csv -tf 132049000 -ti 10498049
./main -fmt rar -out output.csv -in examples/test_file_5k.csv -ti 1320498000 -tf 1360498049
./main -in examples/test_file_5k.csv -fmt xml -out output.xml -ti 1320498000 -tf 1360498049
