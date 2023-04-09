for((i=1;i<10000;i++));	do
	echo $i
	./gen $i > in
	# cat in
	./a < in > out1
	./b < in > out2
	#python3 p4_brute2.py < in > out2
	diff -w out1 out2 || break
	echo "success"
	cat out1 out2
done
