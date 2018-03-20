./corewar $1 -d $2 > diff
../vm_champs/corewar $1 -d $2 > ../vm_champs/diff
diff -u diff ../vm_champs/diff > diffed
vi diffed
