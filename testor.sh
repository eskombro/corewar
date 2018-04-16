dir=cc/poub/champs
#dir=~/ASM_Corewar_tests

rm $dir/*.cor
for file in $dir/*.s;
do
	echo "==> $file <=="
	./asm $file 2>> bison
	echo ""
	echo ""
done
