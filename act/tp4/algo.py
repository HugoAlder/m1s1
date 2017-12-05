#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys, operator
from collections import Counter

class Job:
    def __init__(self, arrival, nb_machines, length):
        self.arrival = arrival
        self.nb_machines = nb_machines
        self.length = length
        self.start = None
        self.machines = []

    def __repr__(self):
        return "({}, {}, {}, {}, {})".format(self.arrival, self.nb_machines, self.length, self.start, self.machines)

def get_data(filename):
    with open(filename) as f:
        nb_machines = int(next(f))
        nb_jobs = int(next(f))
        jobs = []
        for i in range(0, nb_jobs):
            line = next(f).split()
            jobs.append(Job(int(line[0]), int(line[1]), int(line[2])))
    return (nb_machines, nb_jobs, jobs)

def sort_size(t):
    return sorted(t, key=operator.attrgetter('nb_machines'))

def sort_length(t):
    return sorted(t, key=operator.attrgetter('length'))

def best_pos(job, last_pos):
    '''
    Machines dispos pour config c
    '''
    size = Counter(last_pos)

    for el in size.elements():
        if (size[el] >= job.nb_machines):
            return el
    return max(size)

def idx_less_of_eq(arr, val):
    for i in range(len(arr)):
        if arr[i] <= val:
            return i

def schedule(nb_machines, jobs):
    res = []
    last_pos = [0 for i in range(nb_machines)]
    for job in jobs:
        pos = best_pos(job, last_pos)
        job.start = pos

        for i in range(job.nb_machines):
            idx = idx_less_of_eq(last_pos, pos)
            job.machines.append(idx)
            last_pos[idx] += job.length

        res.append(job)
    return res

if __name__ == '__main__':
    if (len(sys.argv) != 2):
        print("Usage : algo.py <file>")
        sys.exit()
    nb_machine, nb_jobs, data = get_data(sys.argv[1])
    jobs = schedule(nb_machine, data)

    for job in jobs:
        print("{}".format(job.start))
