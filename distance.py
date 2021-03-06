# https://blog.csdn.net/yixianfeng41/article/details/61917158
# Fréchet distance(弗雷歇距离)-用于地图匹配> 主人走路径A，狗走路径B，各自走完这两条路径过程中所需要的最短狗绳长度。-
# original: https://blog.csdn.net/shine302/article/details/79863737
# original of code: https://www.jianshu.com/p/268d31aee5c3
# Hausdorff distance: if = 0, 即任意一个点到另一个集合的点的最小距离的最大值=0 也就是说与之重合


# -*- coding: utf-8 -*-


import math
import numpy as np
class dist():
    # Euclidean distance.
    def euclidean(pt1,pt2):
        return math.sqrt((pt2[0]-pt1[0])*(pt2[0]-pt1[0])+(pt2[1]-pt1[1])*(pt2[1]-pt1[1]))
    """
    Fréchet distance
    """
    def _c(ca,i,j,P,Q):
        if ca[i,j] > -1:
            return ca[i,j]
        elif i == 0 and j == 0:
            ca[i,j] = euclidean(P[0],Q[0])
        elif i > 0 and j == 0:
            ca[i,j] = max(_c(ca,i-1,0,P,Q),euclidean(P[i],Q[0]))
        elif i == 0 and j > 0:
            ca[i,j] = max(_c(ca,0,j-1,P,Q),euclidean(P[0],Q[j]))
        elif i > 0 and j > 0:
            ca[i,j] = max(min(_c(ca,i-1,j,P,Q),_c(ca,i-1,j-1,P,Q),_c(ca,i,j-1,P,Q)),euclidean(P[i],Q[j]))
        else:
            ca[i,j] = float("inf")
        return ca[i,j]

    """
    Computes the discrete frechet distance between two polygonal lines
    Algorithm: http://www.kr.tuwien.ac.at/staff/eiter/et-archive/cdtr9464.pdf
    P and Q are arrays of 2-element arrays (points)
    """
    def frechet(P,Q):
        ca = np.ones((len(P),len(Q)))
        ca = np.multiply(ca,-1)
        return _c(ca,len(P)-1,len(Q)-1,P,Q)
