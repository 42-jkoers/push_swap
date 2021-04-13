SILECE_MAKE = | grep -v -E ".*Leaving directory|.*Entering directory"
NL = @echo ""

all bonus:
	make -C lib/libft/ $(SILECE_MAKE)
	make -C lib/stack/ $(SILECE_MAKE)
	make -C src_checker/ $(SILECE_MAKE)
	make -C src_push_swap/ $(SILECE_MAKE)
	@ln -fs src_push_swap/push_swap push_swap
	@ln -fs src_checker/checker checker

clean:
	make -C lib/libft/ clean $(SILECE_MAKE)
	make -C lib/stack/ clean $(SILECE_MAKE)
	make -C src_checker/ clean $(SILECE_MAKE)
	make -C src_push_swap/ clean $(SILECE_MAKE)

fclean:
	make -C lib/libft/ fclean $(SILECE_MAKE)
	make -C lib/stack/ fclean $(SILECE_MAKE)
	make -C src_checker/ fclean $(SILECE_MAKE)
	make -C src_push_swap/ fclean $(SILECE_MAKE)
	rm -f push_swap
	rm -f checker

visualize500: all
	python3 lib/pyviz.py `ruby -e "puts (0..499).to_a.shuffle.join(' ')"`

visualize100: all
	python3 lib/pyviz.py `ruby -e "puts (0..99).to_a.shuffle.join(' ')"`

visualize5: all
	python3 lib/pyviz.py `ruby -e "puts (0..4).to_a.shuffle.join(' ')"`

visualize3: all
	python3 lib/pyviz.py `ruby -e "puts (0..2).to_a.shuffle.join(' ')"`

eval: all
	@echo "\n\n====== CHECKER ERROR MANAGEMENT ======"
	echo "" | ./checker a b
	$(NL)
	echo "" | ./checker 1 1
	$(NL)
	echo "" | ./checker 1 2147483648
	$(NL)
	./checker
	$(NL)
	echo "not a command" | ./checker 1 2
	@echo "\n\n====== CHECKER FALSE TESTS ======"
	echo "sa " | ./checker 1 2
	$(NL)
	echo "sa\npb\nrrr\n" | ./checker 0 9 1 8 2 7 3 6 4 5
	@echo "\n\n====== CHECKER RIGHT TESTS ======"
	echo "" | ./checker 0 1 2
	$(NL)
	echo "pb\nra\npb\nra\nsa\nra\npa\npa\n" | ./checker 0 9 1 8 2
	@echo "\n\n====== PUSH SWAP IDENTITY TEST ======"
	./push_swap 42
	$(NL)
	./push_swap 0 1 2 3"
	$(NL)
	./push_swap 0 1 2 3 4 5 6 7 8 9
	$(NL)
	@echo "\n\n====== PUSH SWAP SIMPLE VERSION ======"
	./push_swap 2 1 0 | wc -l
	./push_swap 1 5 2 4 3 | wc -l
	./benchmark.sh 5
	./benchmark.sh 5
	@echo "\n\n====== PUSH SWAP MIDDLE VERSION ======"
	./benchmark.sh 100
	./benchmark.sh 100
	./benchmark.sh 100
	@echo "\n\n====== PUSH SWAP ADVANCED VERSION ======"
	./benchmark.sh 500
	./benchmark.sh 500
	./benchmark.sh 500

test:
	@echo "a\n"


re: fclean all

.PHONY: all bonus clean fclean re
