1.	You might have noticed some unexpected behavior when printing the value of P, T, and M variables. Can you explain what is happening?
	
	I didn't experience any problems with printing these values so I can't answer this question.

2.	In this assignment, you used sleep() to coordinate the behavior of two concurrently executing processes. Explain why this is actually a bad idea in general for ensuring the ordering of events between processes. (Later in the course you will learn better ways of coordinating processes.)

	It doesn't confirm that the previous process actually finished.  It's just a guess as to when the last process will be done.

3.	Describe the purpose of the ‘fflush()’ function (i.e. what might happen if we didn’t use it in this program?). (Hint: read ‘man fflush’)
	
	It's used to clear out the write stream buffer before the process is terminated so no information is lost.  If we didn't use it, we could lose part of our output.