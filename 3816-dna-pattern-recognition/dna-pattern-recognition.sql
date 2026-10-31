# Write your MySQL query statement below
select
sample_id,
dna_sequence,
species,
(dna_sequence regexp '^ATG') has_start,
(dna_sequence regexp '(TAA|TAG|TGA)$') has_stop,
(dna_sequence regexp 'ATAT') has_atat,
(dna_sequence regexp 'GGG') has_ggg
from samples
order by sample_id;

