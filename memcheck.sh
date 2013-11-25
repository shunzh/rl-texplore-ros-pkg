#!/bin/sh

rl_exp=`rospack find rl_experiment`
valgrind $rl_exp/bin/experiment --agent texplore --env asterix --prints
