./corewar $1 -v 4 > diff_v
../vm_champs/corewar $1 -v 4 > ../vm_champs/diff_v
diff -u diff_v ../vm_champs/diff_v > diffed_v
vi diffed_v
