## Resources

My main resources apart from lectures material were:
1. A paper at https://udacity-reviews-uploads.s3.amazonaws.com/_attachments/41330/1493863065/pid_control_document.pdf
2. A nice video from MIT lab at https://youtu.be/4Y7zG48uHRo

## The Effect of P, I, D

#### P
P component tries to correct error steering car, so that CTE decreases.

#### D
D tries to prevent overshooting, to watches for CTE change rate to tries to pull in the direction opposite to change,
the quicker is change - the harder it pulls to opposite direction. For example, it prevents oscillation on a straight line,
compensating P pull to a center line with a slight pull to the side. But on a sharp turn D tries to steer back to the center
 line of the road along with P (and I) as CTE error is increasing very fast in the wrong direction.

#### I
I compensates for a control bias, for example if the CTE is always positive (car is always on one side of center line) "I"
will pull the car to center line (as CTEs will sum up and make I component sensible to the total error).

## Tuning of the params

I followed the manual process described in (1) so I increased P first so the car doesnt oscillate too much.
Then kept increasing D until car is able to turn more or less accurately.
In the end added a little of I to make everything a bit more stable.
And that was it.