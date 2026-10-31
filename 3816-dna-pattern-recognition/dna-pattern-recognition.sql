# Write your MySQL query statement below
select sample_id, dna_sequence , species,if (substring(dna_sequence,1,3)="ATG",1 ,0) has_start, if(substring(dna_sequence,-3,3) in("TAA","TAG","TGA"),1,0) has_stop,if(instr(dna_sequence,"ATAT")>0,1,0) as has_atat, if(instr(dna_sequence,"GGG")>0,1,0) has_ggg
from  samples
order by sample_id