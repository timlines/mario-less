#include <cs50.h>
#include <stdio.h>

// Make a piramid for mario
// Only enter values between 1 and 8 exclusivily

int main(void)
{

    // Ask the user for the height of the mario pyramid

    int h;

    do
    {
        h = get_int("Height: ");
    }

    // reject heights less than 1 or greater than 8
    while (h < 1 || h > 8);

    // Make the pyramid

    for (int i = 0; i < h; i++)//use magic to make a pyramid
    {
        for (int j = h - 1; j > i; j--) //use magic to print spaces 
        {
            printf(" "); //print a space to right align hashes
        }
        for (int k = 0; k <= i; k++) //use more magic to print hashes
        {
            printf("#"); // print a hash
        }
        printf("\n"); //A line break after every line. 
    }
}  // This is the last bracket for int main (void)


/*
**Entry**

**Entry 12:04**

It works!!??

for (int i = 0; i < h; i++)
    {
        for(int j = h-1; j > i; j--)
        {
            printf(" ");
        }
        for(int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }

~/pset1/mario/ $ ./mario
Height: 1
#
~/pset1/mario/ $ ./mario
Height: 2
 #
##
~/pset1/mario/ $ ./mario
Height: 3
  #
 ##
###
~/pset1/mario/ $ ./mario
Height: 4
   #
  ##
 ###
####

Now to check it!



**Entry 11:57**

Checking the orginal paramaters I still have one last thing to do.
My code is always added 8 spaces in front of the hashs which is wrong, so when I 
print a 1 or 2 row it is right justifited.

~/pset1/mario/ $ ./mario
Height: 2
       #
      ##

This is close,but it should be:

 #
##

The hash on the bottom needs to be all the way to the left. 

So how do I change this?

It looks like the problem is in my space for loop. It always starts counting at 7 where
it should start based on what the user input is minus 1. So h - 1?

If I enter 8 it wll be 7
7 - 1 = 6
6 - 1 = 5
5 - 1 = 4
4 - 1 = 3
3 - 1 = 2
2 - 1 = 1
1 - 1 = 0

Won't zero mess this up? I'll check it.



**Entry 11:53**


for (int i = 0; i < h; i++)
    {
        for(int j = 7; j > i; j--)
        {
            printf(".");
        }
        for(int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }

Height: 8
.......#
......##
.....###
....####
...#####
..######
.#######
########

I think we've done it! Now to check it off.

Oh right, I need to remove the dots. 


**Entry 11:49

That's just about it. 

for (int i = 0; i <= h; i++)
    {
        for(int j = 8; j > i; j--)
        {
            printf(".");
        }
        for(int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
        
~/pset1/mario/ $ ./mario
Height: 8
........#
.......##
......###
.....####
....#####
...######
..#######
.########
#########

It's almost perfect but there are still a few mistakes. All this was fixed because
in the second for loop it needed to be

 for(int k = 0; k <= i; k++)
 
 k <= i K needed to be less than or equal to i. 

Now if i just change the first loop to be < h it should do it? Maybe also the first 
for loop too. 


**Entry 11:34**

So why is it printing this extra row of dots at the top?

And why isn't it also printing the hash on the first line?

for (int i = 0; i <= h; i++) // this one needs to start at zero
    {
        for(int j = 8; j > i; j--) //this one needs to count down
        {
            printf(".");
        }
        for(int k = 0; k < i; k++) // this one needs to count up
        {
            printf("#");
        }
        printf("\n");
    }
    
~/pset1/mario/ $ ./mario
Height: 8
........
.......#
......##
.....###
....####
...#####
..######
.#######
########

Let me run through it again

i = 0; 0 <= 8; (true) 0+1 = 1

So it will run the first and second for loops. 

The first for loop will start at 8, then
8 > 0 (T); 8 - 1, = 7
7 > 0 (T); 7 - 1, = 6
6 > 0 (T); 6 - 1, = 5
5 > 0 (T); 5 - 1, = 4
4 > 0 (T); 4 - 1, = 3
3 > 0 (T); 3 - 1, = 2
2 > 0 (T); 2 - 1, = 1
1 > 0 (T); 1 - 1, = 0
0 > 0 (FALSE)

So what this is saying is that it will print the dots 8 times. 
This is actually incorect we only want it to prin 7 times and then add a hash.

What about the next for loop?

for (int k = 0; k < i; k++)

k = 0, 0 < 0; Zero is not less than zero so it is false and doesn't print one hash. 

Wait I thought this worked before?!




for (int i = 0; i <= h; i++)
    {
        for(int j = 8; j > i; j--)
        {
            printf(".");
        }
        for(int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("\n");



**Entry 11:27**

for (int i = 0; i <= h; i++) // this one needs to start at zero
    {
        for(int k = 0; k < i; k++) // this one needs to count up
        {
            printf("#");
        }
        for(int j = 8; j > i; j--) //this one needs to count down
        {
            printf(".");
        }
        printf("\n");
    }

Fliping the too loops didn't work:

Height: 8   
........
#.......
##......
###.....
####....
#####...
######..
#######.
########

Again not what I'm looking for, so that means that the dots for loop needs to be in 
front of the hashes. 

**Entry 11:17**

Okay I'm really close.

for (int i = 0; i <= h; i++) // this one needs to start at zero
    {
        for(int j = 8; j > i; j--) //this one needs to count down
        {
            printf(".");
        }
          for(int k = 0; k < i; k++) // this one needs to count up
        {
            printf("#");
        }
        printf("\n");
    }

~/pset1/mario/ $ ./mario
Height: 8
........
.......#
......##
.....###
....####
...#####
..######
.#######
########

Right, I'm really close! The trick is here:

 for(int j = 8; j > i; j--) 
 
 To count down, all I needed to do was set the j to 8, and then change the boolean
 expression from j < i to j > i. Simple I know. 
 What this means is it starts at 8 and then counts down to 0, each time it's compared
 to i which is counting up startig at 0. So it goes
 
 j = 8; 8 > 0; 8-1, then
 j = 7; 7 > 0; 7-1, = 6 and so on. 
 
 But I still have a problem, the first line here is 8 dots. Where it needs to be
 seven dots and one hash. 
 
 The problem is when I swithed it to 7 it didn't fix it it just did this: 
 
 ~/pset1/mario/ $ ./mario
Height: 8
.......
......#
.....##
....###
...####
..#####
.######
#######
########

The first line is still 7 hashes. And now the lines that follow are also incorrect because
there is not enough hashes. Maybe I just need to put the hashes first? I'll try moving
the for loop.
 
 

**Entry 10:54**

I keep comiing back to this:

for (int i = 0; i <= h; i++) 
    {
        for(int j = 7; j > 0; j--) 
        {
            printf(".");
        }
          for(int k = 0; k < i; k++) 
        {
            printf("#");
        }
        printf("\n");
    }

But it only results in this:

~/pset1/mario/ $ ./mario
Height: 8
.......
.......#
.......##
.......###
.......####
.......#####
.......######
.......#######
.......########

It doesn't count down. The problem is here:

for(int j = 7; j > 0; j--) 

What I want it to do in my head is have J start at 7, and then check if it is greater than
0, which is true, so it does 7 - 1 and J is now 6. The problem is that is does this
7 times every time. It needs to adjust to the row high which is i. So maybe I do 
7 - i? What would that do

j = 7 - 0; 7 > 0; 7 - 1.
j = 6 - 1; 6 > 0; 6 -1. 

The problem here is that the first value needs to always be 7 
If J changes then it just takes away too many spaces or dots. 
So the problem now is that J changes by one


**Entry 10:21**

Okay so I ran this:

for (int i = 0; i <= h; i++) // this one needs to start at zero
    {
        for(int j = 8 - i; j > i; j--) //this one needs to count down
        {
            printf(".");
        }
          for(int k = 0; k < i; k++) // this one needs to count up
        {
            printf("#");
        }
        printf("\n");
    }
    
And got this:

~/pset1/mario/ $ ./mario
Height: 8
........
......#
....##
..###
####
#####
######
#######
########

As I can see above it's almost working. The first row printed 8 which is wrong, it should 
only print seven, but the second row is actually right. 
It's printing 6 dots and one hash, it should print 6 dots which is right but then it should
print two hashes


**Entry 10:16**

Interesting, changing the variable to K didn't change anything, it's still doing the 
same thing. 

~/pset1/mario/ $ ./mario
Height: 5
........
........#
........##
........###
........####
........#####

for (int i = 0; i <= h; i++) // this one needs to start at zero
    {
        for(int j = 8; j > 0; j--) //this one needs to count down
        {
            printf(".");
        }
          for(int k = 0; k < i; k++) // this one needs to count up
        {
            printf("#");
        }
        printf("\n");
    }

I think I'm pretty close here I just need to count down on the dots. The problem
I have here is that I have 8 hardcoded into the for loop. What I need to do 
is start at 8 but then count down to 0. How can I do that?

**Entry 10:12**

Okay this is what I got:

~/pset1/mario/ $ ./mario
Height: 8
........
........#
........##
........###
........####
........#####
........######
........#######
........########

The funny thing is this almost solves the second problem. lol. So I might have
to save this for the next harder challenge. 

for (int i = 0; i <= h; i++) // this one needs to start at zero
    {
        for(int j = 8; j > 0; j--) //this one needs to count down
        {
            printf(".");
        }
          for(int j = 0; j < i; j++) // this one needs to count up
        {
            printf("#");
        }
        printf("\n");
    }
    
One note here, the first hash is missing. Oh I think that's because I have duplicate J
so I'll make a k now for the third four loop. 

**Entry 10:04**

Lol, my entries are ascending, I'll try desending next time.
Right so I ran this code
for (int i = h; i >= 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            printf(".");
        }
          for(int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }


And got this:

Height: 8
........########
.......#######
......######
.....#####
....####
...###
..##
.#

The good news is it's working, it's added the dots to the # but my hashs are going in
in the wrong order, then need to count up as the dots count down. The thing is I 
already know how to count up, but I changed my first four loop to count down. Maybe I
I could change the first for loop to be what is was before, counting up from 0 to 8, 
and then add a second for loop counting down for the dots, and a third four loop counting
up for the hashes?


**Entry 9:55**

for (int i = h; i >= 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            printf("#");
        }
            printf("\n");
    }

Okay I ran this code and got this:


~/pset1/mario/ $ ./mario
Height: 8
########
#######
######
#####
####
###
##
#


It counted down! But does it work everytime with differnt numbers 1-8?

~/pset1/mario/ $ ./mario
Height: 5
#####
####
###
##
#

Great it works! 

Okay, earlier I was able to combine multiple for loops togther so mabye I add a
second for loop?



**Entry 9:50**

for (int i = h; i <= 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            printf("       #");
        }
            printf("\n");
    }

So this just returned: 
~/pset1/mario/ $ ./mario
Height: 8

It didn't print anything. maybe if I take a closer look at what I said

i = 8; i <= 0; i--. The boolean expression is checked but it prooved false so there the 
program ended. makes sense. How do I make it count down?


**Entry 9:40**

Another forever loop:
for (int i = 8; i <= h; i--)
    {
        for(int j = 8; j < i; j--)

I'll set the seond J to 7.

**Entry 9:38AM**
Great that just puts it in a forever loop. Press ctrl + c end its. 
Better adjust the second for loop.

**Entry 9:25AM**
In the next test let me try add spaces or dots to see what happens.

it returned the following:

       #
       #       #
       #       #       #
       #       #       #       #
       #       #       #       #       #
       #       #       #       #       #       #
       #       #       #       #       #       #       #
       #       #       #       #       #       #       #       #

It makes sense, all we did was add each spaces so it added 8 spaces before every hash
mark. The first hash mark is actually in the correct spot for an 8 high rows, but the
following rows are incorrect. The second row only should have 6 spaces instead of 7
and the space can't be before each hash mark, it should only be 6 spaces followed by 
two hashes. Like this:

       #    Row 0: 7 spaces, 1 hash
      ##    Row 1: 6 spaces, 2 hashes
     ###    Row 2: 5 spaces, 3 hashes
    ####    Row 3: 4 spaces, 4 hashes
   #####    Row 4: 3 spaces, 5 hashes
  ######    Row 4: 2 spaces, 6 hashes
 #######    Row 4: 1 spaces, 7 hashes
########    Row 4: 0 spaces, 8 hashes

They mentioned listed a table like this to help find the pattern. The patern here is
obvious, it starts with 7 spaces and 1 hash, the spaces go down by one every row, and
the hashes go up by one every row. The study guide also mentioned replacing the spaces 
with dots. So maybe the key is to first think the frist row should have 7 dots and 1 has.
How do I print 7 dots? Right now the for loop is counting up but do start at 7 I need
to count down. How do I count down?

Let me try to set the first i to i-- and then set i = 8. 


**Entry 9:23AM**
These two for loops together will make a left aligned pyramid, Now I have to figure out
how to make it right aligned. The difference was just in the sendond for statement,
by making the seconded condidtion j < i, it refered to the frist i, in the first statement
the for loop counts up to 8 then compares it to j. It prints the  # 8 times because the 
first for loop has it run 8 times. J then counts up but becasue it starts at 0 it only 
makes it to seven before j < i is false or 7 < 8.

Wait I think I'm wrong it starts from top to bottom, so the first for loop runs, it sets
i to zero, it checks that 0 <= to h which is 8, which is true, so it adds 1 to i. So now
i == 1.
Then it goes to the next loop, it sets j to zero, then checks if 0 is less than i which is
now 1. It then adds j sets j to 1. 

Since the 2nd for statement was true it will print one # because it only ran one time.

After the second for loop as printed one line, it then adds a newline.

Now it runs the frist for loop again, i = 1, 1 <= 8; 1 + 1, So now i is now 2.

it repeats the second loop, j starts at 0 again, j = 0; 0 < 2; 0 + 1. J is set to 1.it runs the for loop one time it is true
so it prints a #, it then runs it a second time. j = 1; 1 < 2; 2 + 1. J is set to 3. it prints # another time, 
J is now 3; then 3 < 3 proves false so it stops printing. 

It repeats this same process everytime until it reaches 8 rows. 

for (int i = 0; i <= h; i++)
    {
        for(int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    

This is how it should be formatted for 8 rows, now to add it to the loop.ma
printf ("       #\n      ##\n     ###\n    ####\n   #####\n  ######\n #######\n########\n\n");


Technically this works, but this is a bad way of doing it.

if (n == 1)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
else if (n == 2)
{
    printf(" #\n##\n");
}

else if (n == 3)
{
    printf("  #\n ##\n###\n");
}
else if (n == 4)
{
    printf("   #\n  ##\n ###\n####\n");
}
else if (n == 5)
{
    printf("    #\n   ##\n  ###\n ####\n#####\n");
}
else if (n == 6)
{
    printf("     #\n    ##\n   ###\n  ####\n #####\n######\n");
}
else if (n == 7)
{
    printf("      #\n     ##\n    ###\n   ####\n  #####\n ######\n#######\n");
}
else if (n == 8)
{
    printf("       #\n      ##\n     ###\n    ####\n   #####\n  ######\n #######\n########\n");
}


This was my first test but all it does is print a column. :(

for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {


    printf("#");

    printf("\n");
    }
}
printf("\n");


Print a box

for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {
             printf("# ");
    }
    printf("\n");
}




It's easier to build a left align piramid
use a for loop

for (int i = 0; i < 10; i++) //initialization; condition; update
{
    // printf("hello!\n");
}

}
For each row
print the correct number of hashes
print a new line


       #    Row 0: 6 dots 1 hash
      ##    Row 1: 5 dos, 2 hash
     ###    Row 2:
    ####
   #####
  ######
 #######
########

#
##
###
####
#####
######
#######
########

// add dots to the left side
// then replace dots with spaces

*/
