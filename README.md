# AASTMT | College of Artificial Intelligence
## High Performance Computing ![](https://img.shields.io/badge/Semester-Fall--2023-red)
---
## This Course is Conducted By:
- _Prof. Dr. Yasser Hanafy_
- _Eng. Ahmed M. Elsayed_
- _Eng. Habiba Assem_
- _Eng. Nagy K. Aly_

| # | Topic | Content |
| ------ | ------ | ------ |
| 1 | Basics | Write & compile codes, calculate runtime, Compiler Optimization |
| 2 | DMA | 1D and 2D Dynamic Memory Allocation |
| 3 | Matrix Multiplication |  Blocked, Column Order, and Row Order Matrix Multiplication |
| 4 | Threads | Threads in C, Threaded Matrix Multiplication |
| 5 | OpenMP | Threads Automation using OpenMP |
| 6 | CUDA | GPU utilization using CUDA |


## usefull commands
| info	| command |
| ------ | ------ |
| compile code | gcc file.c -o file |
| compile code with pthread | gcc file.c -o file -lpthread |
| submit sequential job | sbatch submit.seq "./col_order-mm.c" |
| monitor jobs progress | watch -n 1 "squeue" |
| submit job and calculate time| sbatch submit.seq "time ./col_order-mm.c" |
| submit job and profile cache hit/miss| sbatch submit.seq "perf stat -d ./col_order-mm.c" |
| submit job with input from file| sbatch submit.seq "perf stat -d ./dot-product" "data_50000_5000" |
| submit threaded job | sbatch submit.pthread "./col_order-mm.c" |
| submit openmp job | sbatch submit.omp "./col_order-mm.c" |
| submit cuda job | sbatch submit.gpu "./col_order-mm.c" |
