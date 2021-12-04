# OS_Lab2
Function isNeed for instances needed in each process which take allocated resources from maximum resources.  
Function isSafe for find if system is in safe state.  Store safe sequence and make a copy of available resources. If all processes are not finished or cannot find next process in safe sequence, system might not in a safe state. Check process is finished or not and go to next condition if no.
If all needs for p are satisfied, add the allocated resources to cop.
In main, read process and resources from customed input file, store process number to define sequence of safe processing. Check available instances and alloted or maximum instances need for each instance, check system in safe state or not at the end and list those.
