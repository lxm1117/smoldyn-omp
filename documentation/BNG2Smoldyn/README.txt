This README file pertains to the BNG2Smoldyn distribution.

There are 2 versions of the BNG2Smoldyn utility program here.  Both of them convert BioNetGen output to Smoldyn input, and both were written by Weiren Cui in 2013.  They are called b2s.pl and b2s.jar.  Both converters function, although the b2s.pl is probably more useful.

b2s.pl - This program is located in the BNG2Smoldyn parent directory.  This is a simple perl interpreter that takes the reaction network output from BioNetGen, which is suffixed with .net, and rewrites it in the Smoldyn input format, suffixed with .txt.  This is a very short and self-explanatory program.  It does not have any documentation.  This program is probably fairly useful.

b2s.jar - This program is located in the BNG2Smoldyn/GUI directory.  This java program creates a GUI that helps the user create a model, then expands the reaction network using BioNetGen, and then converts it to Smoldyn and runs it in Smoldyn.  This is an incomplete project, which I don't plan to maintain.  It is documented in the file called User_Guide_BNG2Smol_GUI.pdf.

Feel free to e-mail me at support@smoldyn.org for assistance.

