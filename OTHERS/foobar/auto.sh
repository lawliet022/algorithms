for((i=5000;i<10000;i+=5));	do
	echo $i
	./gen $i > in
	# cat in
	#./a < in > out1
	#./b < in > out2
	python2.7 p3_2.py < in > out1
	python2.7 tester.py < in > out2 || (1 == 1)
	diff -w out1 out2 || break
	echo "success"
	cat out1 out2
done
