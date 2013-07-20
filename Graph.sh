while read line; do
if [ "$line" != "EOF" ]; then
echo "$line" >> Sensor.txt
else
break
fi
done < /dev/ttyUSB0
sed -e 's/[\t ]//g;/^$/d' Sensor.txt > Finput.txt
awk 'NR%2==0' Finput.txt | cat > sensor1.txt
awk 'NR%2!=0' Finput.txt | cat > sensor2.txt
g++ main.cpp
./a.out
#rm a.out
#rm sensor1_out.txt
#rm sensor1.txt
#rm senssor2.txt
g++ processor.cpp
./a.out 
#r a.out
#rm X-axis.txt
#rm Y-axis.txt
echo "Enter name by which graph is to be saved:"
read a
if [ ! -d "Previous" ]; 
then
mkdir Previous
fi

/usr/bin/gnuplot  <<_EOF_
set xrange [-10:50]
set yrange [310:0]
set style data linespoints
set terminal svg
plot 'output.txt'lc rgb 'black'
set xlabel 'Stress'
set ylabel 'Strain'
set key off
plot 'output.txt' 
set title 'Sensor Plot'

	
set term postscript eps enhanced "Helvetica" 24
set output '$a.svg'
replot
_EOF_

mv $a.svg Previous
cd Previous
gimp "$a.svg"
cd ../
rm output.txt -f
rm Finputss.txt -f
set output '$a.svg'
replot
_EOF_

mv $a.svg Previous
cd Previous
gimp "$a.svg"
cd ../
rm output.txt -f
rm Finputss.txt -f
