SUBDIRS = src
dist_doc_DATA = README.md COPYING NEWS AUTHORS ChangeLog

ChangeLog: .git
	git log --format="%ai%x09%an <%ae> %n%n%x09* %s%n%n" > $@

AUTHORS: .git
	git log --format="%an <%ae>" | sort -u > $@

README: README.md

