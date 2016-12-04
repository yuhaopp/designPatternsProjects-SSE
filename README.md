# designPatternsProjects-SSE
This repository is created for managing our design patterns projects.

Master branch is old version of our projects.

And our goal is reconstruct the old project to patterns.

Until now(2016-12-04 22:04:57),we have realized some useful design patterns, they are:

1. Factory pattern.
    We use this pattern to create all kinds of enemies we need. You just need to tell how many typeA or TypeB or other enemies should be  created to factory, and the details could be coorperated by it. This pattern couold unify different objects's instantiation。
2. Observer pattern.
    It is necessary for our application to get some palyers' current situations(such as HP, is posioned, score) to show on screen timely. So we need an observer to monitor these information and refresh the show screen.

3. Facade pattern.
    As our game need users control hero by keyboard, some people like up/down/left/right key, however, others may like W/A/S/D. So we add a function--The custom keyboard. And to realize this, we use the facade pattern. It is simple, just intercept users' operation functions and do some packaging to touch off the other function. Such as the user pressed the 'w', we will do some judgement. And according to users' settings(if is not settted, use default setting), we could do the corresponding operations.
    

And of course, we did a lot of jobs on project structure's improvement:

1. 
