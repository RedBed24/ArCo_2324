#!/usr/bin/python

import subprocess

def main() -> None:
    BASE = 2
    START_POWER = 7
    END_POWER = 15
    MULTIPLIER = 1
    TIMES_TO_RUN = 5

    PROGRAMS = ["../../src/complexmul.cpp", "complexmul_vectorized.cpp"]

    sums = []

    for power in range(START_POWER, END_POWER + 1):
        sums.append([])
        for n_program in range(len(PROGRAMS)):
            sums[-1].append(0)
            for run in range(TIMES_TO_RUN):
                # Change problem size
                subprocess.Popen(f"sed s/TAMAÑO/{MULTIPLIER * BASE ** power}/ {PROGRAMS[n_program]} > bin/tmp{n_program}.cpp", shell=True).wait()
                # Compile
                subprocess.Popen(f"icpx -fopenmp -g -O0 -o bin/{n_program} bin/tmp{n_program}.cpp", shell=True).wait()
                # Run and keep output
                process = subprocess.Popen(f"bin/{n_program}", shell=True, text=True, stdout=subprocess.PIPE)
                process.wait()
                output = process.stdout.read()

                time, c_contents = parse_output(output)
                print(f"Program {PROGRAMS[n_program]} with {MULTIPLIER}*{BASE}^{power} = {MULTIPLIER * BASE ** power} size took {time}s in {run = }")
                sums[-1][-1] += time

            sums[-1][-1] /= TIMES_TO_RUN
            print(f"Program {PROGRAMS[n_program]} with {MULTIPLIER}*{BASE}^{power} = {MULTIPLIER * BASE ** power} size took {time}s avg")
    
    # sums[tamaño_problema][programa]
    print(sums)

def parse_output(output : str) -> tuple:
    c_contents, time, _ = output.split("\n")
    c_contents = [float(value) for value in c_contents.split()]
    return float(time), c_contents

if __name__ == "__main__":
    main()

