# Codio Tutorial

### 1. Open Terminal
- Tool -> Terminal

### 2. Modify the code
- All the code that needs to be modified is inside the directory **~/workspace/FOSSSim/**
- Only touch the `.cpp` files to make sure that you do not corrupt the interfaces to the basic library

### 3. Delete your files and restart
- Project -> Delete to delete your virtual box
- After deletion, you may restart your assignment from the **Launch Codio** below

### 4. Steps to compile the code
- Open a new terminal (the current dir should be ~/workspace which is the base directory of your code)
- `mkdir build`
- `cd build`
- `cmake ..` This examines the system configuration and generates a makefile
- `ccmake .` [Optional] To configure the build system
- `make` To build the program
- The binary executable is now in the `build/FoSSSim` directory
    - Go to this dir and execute `./FOSSSim` without arguments
        - This will show you a brief description of the arguments
    - `./FOSSSim -s` to load a scene
        - For e.g. To load the scene `~/workspace/assets/t1m1/StarterTests/helloworld.xml`, type the following
            - `./FOSSSim -s ~/workspace/assets/t1m1/StarterTests/helloworld.xml`
- Click the **Virtual Desktop** on the menu bar to remote control your desktop
    - You should see a window that displays a ‘Hi' that is made of balls and rods. Press <S> for single stepping, or <SpaceBar> to run the simulation (if there is any).

## Oracle
- You may run the oracle located in the `~/workspace/oracle` directory, in the same way you run your own code. For example, you may use
    - `~/workspace/oracle/FOSSSimOracleT1M1 -s <scene_file>`
- For example: (to run the oracle for T1M1)
    - `~/workspace/oracle/FOSSSimOracleT1M1 -s ~/workspace/assets/t1m1/StarterTests/helloworld.xml`


## Compare your result with the oracle
- You may also compare with your assignment by first running your assignment and write your result to a file, for example, use the "-o" argument to write your result to "output.bin" (where "-d 0" means no display):
    - `./FOSSSim -s ~/workspace/assets/t1m1/InertiaTests/test00explicit.xml -o output.bin -d 0`
- Then you can use "-i" argument to read your result back and compare with the oracle:
    - `~/workspace/oracle/FOSSSimOracleT1M1 -s ~/workspace/assets/t1m1/InertiaTests/test00explicit.xml -i output.bin -d 0`
- If you do your assignment correctly, you'll see all "Passed" shown in the output of the comparison. 
    
## Submission
- Please use the menu item "Education -> Mark as Completed"
    
**NOTE:** Submission is only allowed once for each milestone. Once you submitted, all your files will become read-only. There will be two files stdout.txt and stderr.txt which appear under ~/workspace/ after submission. They record the output during auto-grading.

**IMPORTANT:** Complete your creative video submission before you submit the coding assignment. Once you submitted, all your files will become read-only, and you will not have a way to work on the creative video submission.
