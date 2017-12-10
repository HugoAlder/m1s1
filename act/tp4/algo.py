#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys, operator
from collections import Counter

class Job:
    def __init__(self, id, arrival, nb_machines, length):
        self.id = id
        self.arrival = arrival
        self.nb_machines = nb_machines
        self.length = length
        self.start = None
        self.machines = []

    def __repr__(self):
        return "(id={}, arrival={}, nb_mach={}, len={}, st={}, mach={})".format(self.id, self.arrival, self.nb_machines, self.length, self.start, self.machines)

def get_data(filename):
    with open(filename) as f:
        nb_machines = int(next(f))
        nb_jobs = int(next(f))
        jobs = []
        for i in range(nb_jobs):
            line = next(f).split()
            jobs.append(Job(i, int(line[0]), int(line[1]), int(line[2])))
    return (nb_machines, nb_jobs, jobs)

def sort_by(t, attr):
    return sorted(t, key=operator.attrgetter(attr))

def best_pos(job, last_pos):
    '''
    Retourne la "meilleure" position
    '''
    size = Counter(last_pos)
    print(size)
    res = []

    # We search for the min position that has enough machines space
    for el in list(size):
        print("el {}".format(el))
        nmach = 0
        for e in list(size):
            if e < el:
                nmach += size[e]
        print('nmach {}'.format(nmach))
        print('job.arrival {}'.format(job.arrival))
        if (nmach >= job.nb_machines) and job.arrival <= last_pos[last_pos.index(el)]:
            if el not in res : res.append(el)

    # If res is empty, it means it needs all the machines
    # So we take the max position
    if len(res) == 0:
        r = max(list(size))
        if r >= job.arrival:
            return r

    # We're taking the first possible position
    print("res {}".format(res))
    for r in sorted(res):
        if r >= job.arrival:
            return r

    # Otherwise, we just take its arrival
    return job.arrival

def best_pos_bis(job, last_pos):
    count = Counter(last_pos)
    res = []

    for el in list(count):
        if count[el] >= job.nb_machines and el >= job.arrival:
            res.append(el)

    if len(res) == 0:
        r = -1
        for el in count:
            if el > r:
                r = el
        if r + 1 >= job.arrival:
            return r + 1
        return job.arrival

    return min(res)

def idx_less_or_eq(arr, val, machines):
    for i in range(len(arr)):
        if arr[i] <= val and i not in machines:
            return i

# Retourne tous les trous (blanks) compatibles à l'insertion d'un job en fonction de la durée
def blank_length_ok(blanks, job, nb_machines):
    res = []
    for blank in blanks:
        if blank[2] - blank[1] >= job.length and blank[1] >= job.arrival:
            res.append(blank)
    return res

# Retourne un ensemble de machine capable de faire tourner un job donne
def suitable_machines(blanks, job, nb_machines):
    blo = blank_length_ok(blanks, job, nb_machines)
    for blank in blo:
        res = []
        tmp = []
        for blank2 in blo:
            if blank[1] == blank2[1]:
                res.append(blank2[0])
                tmp.append(blank2)
        if len(res) >= job.nb_machines:
            job.start = blank[1]
            for rmv_blk in tmp:
                blanks.remove(rmv_blk)
            return res
    res = []
    return res

def schedule(nb_machines, jobs):
    res = []
    last_pos = [0 for i in range(nb_machines)]
    
    # Tableau de tous les blanks dans l'ordonnancement
    blanks = []

    for job in sort_by(jobs, "arrival"):

        # D'abord verifier si on peut combler un trou
        sm = suitable_machines(blanks, job, nb_machines)
        if len(sm) > 0:
            for machine in sm:
                job.machines.append(machine)

        # Si c'est impossible, on cherche a mettre le job en bout de liste
        else:
            pos = best_pos_bis(job, last_pos)
            job.start = pos

            for i in range(job.nb_machines):
                idx = idx_less_or_eq(last_pos, pos, job.machines)
                job.machines.append(idx)
                tmp = last_pos[idx]
                last_pos[idx] = pos + job.length

                # Ajout d'un blank
                if tmp + job.length < last_pos[idx]:
                    blank = [i, tmp, last_pos[idx] - job.length]
                    blanks.append(blank)

        res.append(job)
    return res

if __name__ == '__main__':
    if (len(sys.argv) != 2):
        print("Usage : algo.py <file>")
        sys.exit()
    nb_machine, nb_jobs, data = get_data(sys.argv[1])

    #tmp = sort_by(data, "length")
    #tmp2 = sort_by(tmp, "nb_machines")
    jobs = sort_by(schedule(nb_machine, data), "id")

    for job in jobs:
        #if job.start > 37200 and job.start < 39600: print(job)
        print("{}".format(job.start))
