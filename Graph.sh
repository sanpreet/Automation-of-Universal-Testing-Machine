#while read line; 
#do
 #   if [ "$line" != "E" ]; then
  #      echo "$line" >> Sensor.txt
   # else
    #    break
    #fi
#done < /dev/ttyUSB0

sed -e 's/[\t ]//g;/^$/d' Sensor.txt > Finput.txt
awk 'NR%2==0' Finput.txt | cat > sensor1.txt
awk 'NR%2!=0' Finput.txt | cat > sensor2.txt
g++ main.cpp
    ./a.out
    rm a.out
#rm sensor1_out.txt
#rm sensor1.txt
#rm senssor2.txt
g++ processor.cpp
    ./a.out 
#rm a.out
#rm X-axis.txt
#rm Y-axis.txt
echo "Enter name of graph:"
read name
    if [ ! -d "Previous" ]; 
    then
        mkdir Previous
    fi

/usr/bin/gnuplot  <<_EOF_
set yrange [-10:50]
set xrange [320:0]
set terminal svg
set xlabel 'Deformation'
set ylabel 'Force'
set key off
set timestamp "%d/%m/%y %H:%M" 80,-2 "Helvetica"
set style data linespoints

plot 'output.txt' lt 2 lc rgb "red" lw 3
set title 'Sensor Plot'
set term postscript eps enhanced "Helvetica" 24
set output '$name.svg'
replot
_EOF_

mv $name.svg Previous
cd Previous
gimp "$name.svg"
cd ../
#rm output.txt -f
#rm Finputs.txt -f
