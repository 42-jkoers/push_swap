SILECE_MAKE = | grep -v -E ".*Leaving directory|.*Entering directory"

all bonus:
	make -C src_checker/ $(SILECE_MAKE)
	make -C src_push_swap/ $(SILECE_MAKE)
	@ln -fs src_push_swap/push_swap push_swap
	@ln -fs src_checker/checker checker

clean:
	make -C src_checker/ clean $(SILECE_MAKE)
	make -C src_push_swap/ clean $(SILECE_MAKE)

fclean:
	make -C src_checker/ fclean $(SILECE_MAKE)
	make -C src_push_swap/ fclean $(SILECE_MAKE)

visualize500: all
	python3 lib/pyviz.py `ruby -e "puts (0..500).to_a.shuffle.join(' ')"`

visualize12: all
	python3 lib/pyviz.py `ruby -e "puts (0..12).to_a.shuffle.join(' ')"`

re: fclean all

.PHONY: all bonus clean fclean re
