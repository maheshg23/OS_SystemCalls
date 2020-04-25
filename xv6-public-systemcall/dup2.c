int
main(int argc, char *argv[])
{
	int fd1,fd2;
    fd1 = open(argv[1], O_RDWR);
	//fd2 = open(argv[2], O_RDONLY|O_CREATE|O_RDWR);
	fd2 = 6;	
    //fd2 = (int) argv[2];
	printf(1,"Before fd1: %d fd2: %d \n",fd1,fd2);
	fd2 = dup2(fd1,fd2);

	printf(1,"Fd Duplicated fd1 %d fd2 %d \n",fd1,fd2);
	char buf[512];
    int i;
    int n = read(fd2, buf, 512);
	for (i=0; i<n;i++){
		printf(1,"%c",buf[i]);
    }

	close(fd1);
	close(fd2);

exit();
}