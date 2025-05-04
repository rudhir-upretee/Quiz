==> 'Permission Denied (publickey)' error when I push!"

1. Open git bash (Use the Windows search. To find it, type "git bash") or the Mac Terminal. Pro Tip: You can use any *nix based command prompt (but not the default Windows Command Prompt!)
2. Type cd ~/.ssh. This will take you to the root directory for Git (Likely C:\Users\[YOUR-USER-NAME]\.ssh\ on Windows)
3. Within the .ssh folder, there should be these two files: id_rsa and id_rsa.pub. These are the files that tell your computer how to communicate with GitHub, BitBucket, or any other Git based service. Type ls to see a directory listing. If those two files don't show up, proceed to the next step. NOTE: Your SSH keys must be named id_rsa and id_rsa.pub in order for Git, GitHub, and BitBucket to recognize them by default.
4. To create the SSH keys, type ssh-keygen -t rsa -C "your_email@example.com". This will create both id_rsa and id_rsa.pub files.
5. Now, go and open id_rsa.pub in your favorite text editor (you can do this via Windows Explorer or the OSX Finder if you like, typing open . will open the folder).
6. Copy the contents--exactly as it appears, with no extra spaces or lines--of id_rsa.pub and paste it into GitHub and/or BitBucket under the Account Settings > SSH Keys. NOTE: I like to give the SSH key a descriptive name, usually with the name of the workstation I'm on along with the date.
7. Now that you've added your public key to Github and/or BitBucket, try to git push again and see if it works. It should!
   
===================================================================================

==> How to check if public key is working in GitHub? Type below command:
[]$ ssh -T git@github.com
Hi rudhir-upretee! You've successfully authenticated, but GitHub does not provide shell access.

===================================================================================

==> Where to add public key in Github?
In the upper-right corner of any page on GitHub, click your profile photo, then click  Settings.
In the "Access" section of the sidebar, click  SSH and GPG keys.
Click New SSH key or Add SSH key.
In the "Title" field, add a descriptive label for the new key. For example, if you're using a personal laptop, you might call this key "Personal laptop".
Select the type of key, either authentication or signing. For more information about commit signing, see About commit signature verification.
In the "Key" field, paste your public key.
Click Add SSH key.

===================================================================================
