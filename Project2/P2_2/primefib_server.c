/********************************************************************
//
// Erman Gurses
// Advances Operating Systems COSC 5352
// Project #2: RPC Implementation 
//
// March 27, 2013
// Instructor: Dr. Ajay K. Katangur
********************************************************************/
/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

/********************************************************************
//
// Includes and Defines
//
/********************************************************************/

#include "primefib.h"


/********************************************************************
// isPrime Procedure
// -This procedure determines whether it is prime number or not
//
// Return Value
// ------------
// int                    If it is prime number return 1
//                        else                  return 0
//
//
// Value Parameters
// ----------------
// n       int            It is sent value by prime_1_svc function
//
// Reference Parameters
// --------------------
// N/A
//      	
//
// Local Variables
// ---------------
// i       int            Loop Iteration Variable.
// result  int            To keep true or false information
//                        Whether n is prime or not
//
********************************************************************/
int isPrime (int n){

    // Variables
    int result;
    int  i;
     
    // Do work
    if (n <= 1){
        result = 0; // 1 is not prime
    } else if ((n == 2) || (n == 3)) {
        result = 1; // Hard code 2 and 3
    } else if (n % 2 == 0) {
        result = 0; // Get rid of evens
         
      /* All other cases are out, so now we check
       to see if n is divisible by the odd
       numbers from 3 on. */
    } else {

        i = 3;
        result = 1; // Assume it's prime, then prove
         
        while (1) {
            /* If i^2 is not a root of n, or if
               n % i == 0. (Won't be larger than
               the square.) */
            if ((i * i > n) || (n % i == 0))
                break;
				
                i += 2; // Iterate by 2 to get odds
        } // End while
         
        // Record the answer
        if (i * i > n)
            result = 1;
        else
            result = 0;
    } // End if
      
    // Return the answer
    return result;   
}


/********************************************************************
// prime_1_svc Procedure
// -This procedure counts the order of the prime number.
//
// Return Value
// ------------
// int *                The address of fibonacci number
//
//
// Value Parameters
// ----------------
// N/A
//
// Reference Parameters
// --------------------
// *argp       	 int
// *rqstp      	 struct svc_req
//
// Local Variables
// ---------------
// result static int    n th prime number that is found.
// number        int    n th prime number that is found.
// counter       int    counter to check n th information
// i             int    Loop Iteration Variable.
// n             int    n th information
********************************************************************/
int * prime_1_svc(int *argp, struct svc_req *rqstp){

    static int  result;
    int n,
        number,
        counter;

    n = *argp;
    counter = 1;	
    number = 2;

    // Check the counter to prevent to exceed n th 
    while (counter < n){
    
        // Increase the number by 1 that is sent to function
        number++;

        // Check whether it is prime or not.
        if (isPrime(number)){
            counter++;
        }		
    }
    result = number;
    return &result;
}


/********************************************************************
// fibo_1_svc Procedure
// This function calculates fibonacci numbers
//
// Return Value
// ------------
// long int *           Address of fibonacci number
//
//
// Value Parameters
// ----------------
// N/A
//
// Reference Parameters
// --------------------
// *argp    int
// *rqstp   struct svc_req
//
// Local Variables
// ---------------
// result static  int  	Fibonacci number
// first          int   In the sequence of fibonacci numbers
//                      It is the smallest one
// second         int  	In the sequence of fibonacci number.
//                      It is the second smallest one
// next           int   Calculated Fibonacci number
// i              int   Loop Iteration Variable.	
// number         int   n th information from the client
//
********************************************************************/
long int* fibo_1_svc(int *argp, struct svc_req *rqstp){

    static long   result;
    int first  = 0, 
        second = 1,
        next,
        number,
        i;

    // Assign n th data that is taken from user
    number = *argp;

    for (i = 0; i <= number; i++){

        // If i equal or less than 1,
        // The fibonacci number is already known
        if(i <= 1){
            next = i;
        } else {
        // Calculate the fibonacci number
            next = first + second;
            // Swap them
            first  = second;				
            second = next;
        }
    }
    result = next;
  return &result;
}
