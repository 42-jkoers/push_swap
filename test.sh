make -C push_swap_src silent
python3 pyviz.py `ruby -e "puts (0..100).to_a.shuffle.join(' ')"`