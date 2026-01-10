#!/bin/sh

DIRECTORY=~/.config/hyprthemes

if [  -d $DIRECTORY ]; then
  echo "Source directory exists, skipping..."
else
  echo "Source directory doesn't exist, creating it and it's sub-folders..."
  mkdir $DIRECTORY
  cd $DIRECTORY
  mkdir "themes"
fi

make run