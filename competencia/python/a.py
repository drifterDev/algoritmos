xa, ya = map(int, input().split())
xb, yb = map(int, input().split())
xc, yc = map(int, input().split())

# Gracias wikipedia
if (ya - yb) * (xb - xc) == (yb - yc) * (xa - xb):
    print("TOWARDS")
elif (ya - yb) * (xb - xc) > (yb - yc) * (xa - xb):
    print("RIGHT")
else:
    print("LEFT")


# try:
#     m = (ya - yb) / (xa - xb)
#     if abs(yc - m * xc) < 10 ** (-5):
#         print("TOWARDS")
#     else:
#         vector1 = (xb - xa, yb - ya)
#         vector2 = (xc - xb, yc - yb)
#         producto = vector1[0] * vector2[1] - vector1[1] * vector2[0]
#         if producto > 0:
#             print("LEFT")
#         else:
#             print("RIGHT")
# except:
#     if xb == xc:
#         print("TOWARDS")
#     elif ya < yb:
#         if xb < xc:
#             print("RIGHT")
#         else:
#             print("LEFT")
#     else:
#         if xb < xc:
#             print("LEFT")
#         else:
#             print("RIGHT")
