# Omics and Bioinformatics

*UE; 4TBI703U*

*password: ob2017*



## Introduction

### Definition

- Better understanding the logic behin bioinformatics program.

- Useful for automatically combining several bioinformatics tools (pipeline)

- Automating a repetitive task


### Data & Formats: DataBanks

**Generalist Banks:**

- GenBank, ENA

- UniProtKB

**Specialized DataBanks**

- species

- scientific field (Exemple: OMIM)

- technology

- molecular type

Databanks store informations as flat files. The organization is line by line: **(Field/Descriptor + Content)** and give meaning to the texts.

Text file is different of Word Processing file. Flats file use **ASCII** characters. European databanks use a two letter descriptor while american databanks use longer letters descriptor.

The most widely used format: **FASTA**: *Title* (>text) + *sequence* line(s). The length of the line is not important.

There is two variations of the FASTA format:

- Multi-FASTA (philogeny)

- FASTQ

  ​


```PDB
PDB:	SEQRES 1 A	5 GLY ARG GLU ALA THR
```

```FASTA
FASTA:	> Protein sequence
		GREAT
```



### Tools:

**NCBI GQUERY**

- (Field / Descriptor: Keywords(s)) + Logical_op + (Field / Descriptor: Keywords(s))...
- **Keywords** : Date(year, month, day)  / Organism ...
- **Logical operators** : AND	OR	BUTNOT
- **Query**:

```
(Author: taveau jc) AND (Title:hemoglobin) OR (Title: hemocyanin)
```

**Emboss**

*emboss.sourceforge.net/*

**Python + BioPython**





## Phylogenetics

Foundation of cladistics: Willi Hennig (1913-1976)

It's a series of logical rules for searching relationships (parent/child) without using fossils. The purpose is the reconstruction of evolutionary history of species by comparing gene (or protein) sequences of various species. There is two types of data (organism and molecular data).

In a classical study there is 4 steps:

- Data selection
- Sequence Alignment
- Construction of one (or several) trees
- Determination of robustness of trees



### Data selection:

It consists of choosing a good molecular marker related to the studied taxonomic group.

### Sequence Alignment

Quantification of similarity between 2 sequences.

​	**Comparions & Aligments:**

​	***Hamming Distance***: From 2 seqs of same legnth, measure the differences between these 2 seqs.

​	***Edit Distance or Distance of Levenshtein***: Measure the number of operations in terms of insertions, deletions & substitutions required to transform the sequence S1 into S2.

Managements of indels via gaps (-) and penalties of gap at the creation (+10) and extension (+1).

We have exacts algorithms:
- Needleman & Wunsch
- Smith & Waterman

and algorythm of words (k-tuples):
- FASTA & BLAST: heuristics

#### Needleman & Wunsch
- $S(i,j) = \text{max of :}$  
  1) $S_{i-1, j-1} + M(X_i,Y_j)\ \text{for diagonal}$  
  2) $S_{i-1,j} + P$  
  3) $S_{i,j-1} + P$  

> $P = -2$  
> $M =  \text{BLOSSUM65}$

|       |       | C        | A       | V        | A        | L        | E        |
| :---: | :---: | :------: | :-----: | :------: | :------: | :------: | :------: |
|       | 0     | -2       | -4      | -6       | -8       | -10      | -12      |
| C     | -2    | ↖ **13** | ← 11    | ← 9      | ← 7      | ← 5      | ← 3      |
| H     | -4    | ↑ **11** | ↖ 10    | ← 8      | ↖ 6      | ← 4      | ↖ 5      |
| E     | -6    | ↑ 9      | ↖ **9** | ← 7      | ↖ 6      | ← 4      | ↖ 12     |
| V     | -8    | ↑ 7      | ↖ 8     | ↖ **16** | ← 14     | ← 12     | ← 10     |
| A     | -10   | ↑ 5      | ↖ 14    | ↑ 14     | ↖ **23** | ← 21     | ← 19     |
| L     | -12   | ↑ 3      | ↑ 12    | ↖ 15     | ↑ 21     | ↖ **29** | ← 27     |
| E     | -14   | ↑ 1      | ↑ 10    | ↑ 13     | ↑ 19     | ↑ 27     | ↖ **37** |

- Find the optimal pathway
  - 18 : bottom right : the start 
  - 0 : top left : the end 
  - $CCAVALE\\
     CHEVALE$
  - $C-AVALE\\
     C \hspace{1px} H \hspace{1px} EVALE$ 


# Multiple Sequence Alignements (MSA)

## Simultaneous Alignement of several sequences

- Dynamic programming

  - Alignement of N sequences in a space of N dimensions
  - Memory for 5 sequences of 100 aas = 10Gb of ..... ....

## Progressive Algorithms : ClustalW

- Pairwise Alignements for all the combinations of sequences
- Groups of pairs strating from the closest

  - Hierarchical Ascendant CLassification
  - Tree of scores

- Multiple Alignement of progressive type (greedy algorithm)

### Progressive Algorithms : Center Star Method

- Step 1 : Pairwise Alignement

  - Multi FASTA

- Step 2 : ....

- Step 3 : Aggregate ALignements

  - Add gap in column, shift others

### ClustalW :

- Step 1 : Pairwise Alignements for all the combination of sequences

- Step 2 : Guide Tree

  - Calcul distance :
    - $1 - \frac{y}{x}$ ; $x$ = number of non gap position ; $y$ = identical position
  - Build the guide tree using :

    - UPGMA
    - Neighbor-Joining

  - Used to build the phylogenic tree

- Step 3 : Aggregating the alignements

  - Follow the tress :

    - Start from the closest pairs
    - Compute at each node an alignement using dynamic Programming

  - Three possible cases :

    - Seq vs Seq
    - Seq vs Partial Alignement
    - .....

- Or aggregating - Computing the scores with Sum of Pairs (SOPs)

- Cons : non re evaluation of the alignements during greedy period Iterative Algorithm : MUSCLE

- Optimization of global scores by iterations

## Multiple sequence alignement programs

Newest version of clustal : Clustal O (Clustal omega) Best :

- Clustal W, O
- MUSCLE
- T-Coffee


(Work in progress)


$$\text{log-odds} (S) = \log _2  \left( \frac{P(S)}{0.25 ^L} \right)$$

## UPGMA

|       | A     | B     | C     | D     | E     |
| ----: | :---: | :---: | :---: | :---: | :---: |
| **A** | 0     | 17    | 31    | 21    | 42    |
| **B** | 17    | 0     | 25    | 36    | 28    |
| **C** | 31    | 25    | 0     | 19    | 56    |
| **D** | 21    | 36    | 19    | 0     | 32    |
| **E** | 42    | 28    | 56    | 32    | 0     |
  

|           | A + B | C     | D     | E     |
| --------: | :---: | :---: | :---: | :---: |
| **A + B** | 0     | 28    | 28.5  | 35    |
| **C**     | 28    | 0     | 19    | 56    |
| **D**     | 28.5  | 19    | 0     | 32    |
| **E**     | 35    | 56    | 32    | 0     |

|           | A + B | C + D | E     |
| --------: | :---: | :---: | :---: |
| **A + B** | 0     | 28.25 | 35    |
| **C + D** | 28.25 | 0     | 44    |
| **E**     | 35    | 44    | 0     |
  

|                   | A + B + C + D | E     |
| ----------------: | :-----------: | :---: |
| **A + B + C + D** | 0             | 39.5  |
| **E**             | 39.5          | 0     |

(E:39.5((A,B:17)(C,D:19)):28.25)
