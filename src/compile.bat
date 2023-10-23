gcc -c linear_sorting.c -I ..\include\ -o ..\obj\linear_sorting.o
ar -rs ..\lib\libLinearSorting.a ..\obj\linear_sorting.o
gcc --static -o main main.c -I ..\include\ -L ..\lib\ -lLinearSorting

cls