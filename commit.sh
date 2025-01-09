#!/bin/bash
formattedDate=$(date +'%m/%d/%Y')
git commit -m "Committed $formattedDate"
read -p "Do you want to push commits to the remote repository? [Y/n] " choice
if [[ $choice == [Yy] ]]; then
    git push origin master
fi
