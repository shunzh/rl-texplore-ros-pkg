#!/bin/sh

rl_exp=`rospack find rl_experiment`
#gdb --args $rl_exp/bin/experiment --agent texplore --env fuelworld
gdb --args $rl_exp/bin/experiment --agent texplore --env asterix --prints

