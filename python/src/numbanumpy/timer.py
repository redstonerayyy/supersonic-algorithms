import time

class Timer:
	timers = {}
	@staticmethod
	def start(name):
		Timer.timers[name] = time.time_ns()
	
	@staticmethod
	def stop(name):
		diff = time.time_ns() - Timer.timers[name]
		diffseconds = diff / (10 ** 9) 
		print(name, ":", round(diffseconds, 5), "Seconds")


