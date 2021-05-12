#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>


const char TARGET_GENOME[] = "METHINKS IT IS LIKE A WEASEL!";
const char GENES[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ!";
const float MUTATION_PROBABILITY = 0.05;
const int NUM_CHILDREN_PER_GENERATION = 100;

const size_t GENOME_LEN = sizeof(TARGET_GENOME) - 1;
const int PERFECT_FITNESS_SCORE = sizeof(TARGET_GENOME) - 1;
const size_t NUM_GENES = sizeof(GENES) - 1;



int calc_fitness(const char * child_genome) 
{
    int i, sum = 0;
    for (i = 0; i < GENOME_LEN; i++) 
    {
        sum += (child_genome[i] == TARGET_GENOME[i]);
    }
    return sum;
}

void create_child(char * parent_genome, char * child_genome) 
{
    int i;
    char parent_gene;
    float random_num;
    char random_gene;
    for (i = 0; i < GENOME_LEN; i++) 
    {
        parent_gene = parent_genome[i];
        random_num = (float)rand() / (float)RAND_MAX;  // 0.0 to 1.0
        random_gene = GENES[rand() % NUM_GENES];
        child_genome[i] = 
            random_num <= MUTATION_PROBABILITY ? 
                random_gene 
            : 
                parent_gene;
    }
    child_genome[i] = 0;  // if print as string
}

int main() 
{

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    char parent_genome[GENOME_LEN+1];   // string terminators
    char child_genome[GENOME_LEN+1];
    char surviving_child_genome[GENOME_LEN+1];

    int i, child_fitness, max_fitness = 0;

    srand(time(NULL));

    int generation = 0;
    for (i = 0; i < GENOME_LEN; i++) 
    {
        parent_genome[i] = GENES[rand() % NUM_GENES];
    }
    parent_genome[i] = 0;  // null terminator
    max_fitness = calc_fitness(parent_genome);
    printf("%3d %3d %s\n", generation, max_fitness, parent_genome);

    
    while (max_fitness < PERFECT_FITNESS_SCORE) 
    {
        generation++;
        max_fitness = 0;  // yes, generation can go downhill!
        for (i = 0; i < NUM_CHILDREN_PER_GENERATION; i++) 
        {
            create_child(parent_genome, child_genome);
            child_fitness = calc_fitness(child_genome);
            if (child_fitness >= max_fitness) 
            {
                max_fitness = child_fitness;
                strcpy(surviving_child_genome, child_genome);
            }
        }
        strcpy(parent_genome, surviving_child_genome);
    }
    printf("%3d %3d %s\n", generation, max_fitness, parent_genome);

    gettimeofday(&end_time, NULL);
    long microseconds = 
        (end_time.tv_sec * 1000000 + end_time.tv_usec) - 
        (start_time.tv_sec * 1000000 + start_time.tv_usec);
    printf("Elapsed time: %7.2fms\n", microseconds / 1000.);

    return 0;
}