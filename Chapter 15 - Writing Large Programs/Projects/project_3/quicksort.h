#ifndef QUICKSORT_H
#define QUICKSORT_H

/*
 * quicksort: takes an unsorted array, low and high indicates 
 *            the position in the array and returns the array
 *            in a sorted order.*/
void quicksort (int unsort_arr[], int low, int high);

/*
 * split: takes an unsorted array, the first element is taken 
 *        as  a  "reference" and it traverses from the lowest 
 *        to   the   highest   and  find  a  position for the 
 *        reference element.*/
int split (int unsort_arr[], int low, int high);

#endif 
