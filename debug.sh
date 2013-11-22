#!/bin/sh

rl_exp=`rospack find rl_experiment`
gdb -ex run --args $rl_exp/bin/experiment --agent texplore --env asterix
