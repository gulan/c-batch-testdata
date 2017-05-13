#! /usr/bin/env python

import random

"""
(rep hospital
    (rep ward
        (alt people [
	    (lit patient)
            (lit staff)])))

hospital = ward*
ward = person*
person = patient | staff
patient,staff = ward-id . given-name . surname
"""

PATIENT, STAFF = '0','1'
INITIALS = 'b bl br c ch cr d dr f fl fr g gl gr h j k kr l m n p pr pl r s sr sl st sh t th'.split(' ')
FINALS = 'a ai ao au e ee ea ei i ia ie io iu o oo oa oe oi ou u ua ui ay ey oy uy'.split(' ')

def gen_ward_id():
    i = 1
    while 1:
        yield "%3.3d" % i
        i += 1
    return

def gen_surname():
    def _aux():
        for c in INITIALS:
            for v in FINALS:
                yield c+v
    m = list(_aux())
    random.shuffle(m)
    for i in m:
        yield i.ljust(4)
    return

def gen_surname_hyphen():
    while 1:
        b = gen_surname()
        c = gen_surname()
        for pre in b:
            n = "%s-%s" % (pre.strip(), c.next().strip())
            yield n.ljust(9)
    return

def gen_ward_batches(num_batches=16, max_batch_len=7):
    w = gen_ward_id()
    f = gen_surname()
    s = gen_surname_hyphen()
    def batch_range(): return random.choice(range(max_batch_len))
    def person_type(): return random.choice([PATIENT,PATIENT,STAFF])
    for _ in range(num_batches):
        ward_id = w.next()
        br = batch_range()
        # * A ward may be empty of both staff and patients, but there is
        #   no data generated in this case. If important, it must be
        #   inferred from a gap in ward-ids. It is not important here.
        
        # * A populated ward must have at least one staff member.
        
        # * A ward might have only staff and no patients.
        if br > 0:
            yield (ward_id, STAFF, f.next(), s.next())
        for _ in range(br-1):
            yield (ward_id, person_type(), f.next(), s.next())
    return

def gen_sorted_ward_batches():
    # surname within batch
    def keyf(r): return (r[0],r[3])
    for rec in sorted(gen_ward_batches(), key=keyf):
        yield rec
    return

if __name__ == '__main__':
    for t in gen_sorted_ward_batches():
        print '|'.join(t)

