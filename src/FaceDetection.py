import serial
import cv2 as cv

import importlib

cv_module = importlib.import_module("cv2")
serial_module = importlib.import_module("serial")

print(f"cv2 version: {cv_module.__version__}")
