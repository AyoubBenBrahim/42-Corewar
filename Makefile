VM = vm
ASM = assembly

all : $(VM) $(ASM)

$(VM) :
	make -C $(VM)
$(ASM) :
	make -C $(ASM)

clean_$(VM) :
	make -C $(VM) clean

clean_$(ASM) :
	make -C $(ASM) clean

fclean_$(VM) :
	make -C $(VM) fclean
	
fclean_$(ASM) :
	make -C $(ASM) fclean

clean : clean_$(VM) clean_$(ASM)

fclean : fclean_$(VM) fclean_$(ASM)

re: fclean all

.PHONY: $(VM) $(ASM) clean_$(VM) clean_$(ASM) clean fclean re