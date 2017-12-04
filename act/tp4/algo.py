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
        self.machine = None

    def __repr__(self):
        return "({}, {}, {}, {}, {})".format(self.arrival, self.nb_machines, self.length, self.start, self.machine)

def get_data(filename):
    with open(filename) as f:
        m = int(next(f))
        n = int(next(f))
        t = []
        for i in range(0, n):
            line = next(f).split()
            t.append(Line(int(line[0]), int(line[1]), int(line[2])))
    return (m, n, t)

def sort_size(t):
    return sorted(t, key=operator.attrgetter('nb_machines'))

def sort_length(t):
    return sorted(t, key=operator.attrgetter('length'))

def get_available(job, last_pos):
    '''
    Machines dispos pour config c
    '''
    Counter()

def schedule(m, t):
    res = []
    last_pos = [0 for i in range(m)]
    for line in t:
        if (get_available(t, m, deb) >= line.s):
            line.start =
            res.append(line)
            for i in
            last_pos[]
        else:
            deb += sort_size(res)[0].nb_machine

if __name__ == '__main__':
    if (len(sys.argv) != 2):
        print("Usage : algo.py <file>")
        sys.exit()
    nb_machine, nb_jobs, data = get_data(sys.argv[1])
    print(sort_length(data))
