/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semgment_tree.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:51:26 by nhanafi           #+#    #+#             */
/*   Updated: 2022/06/22 18:52:50 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <complex>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

class SegmentTree{
  int len;
  vector <long long> all;
  vector <long long> seg;
  public:
    SegmentTree(){}
    SegmentTree(vector <long long> inp)
    {
      len = inp.Z;
      all = inp;
      seg.resize(4*len);
      build(1,0,len-1);
    }
  void build(int id, int l, int r)
  {
    if (l==r)
    {
      seg[id] = all[l];
      return ;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    seg[id] = min(seg[2*id],seg[2*id+1]);
  }
  vector <long long> query(int id, int l, int r, int sl, int sr)
  {
    if (r < sl || sr < l)
      return 1e18;
    if (sl <= l && sr >= r)
      return seg[id];
    int mid = (l+r)/2;
    return min(query(2*id,l,mid,sl,sr),query(2*id+1,mid+1,r,sl,sr));
  }
  vector <long long> query(int l,int r)
  {
      return query(1,0,len-1,l,r);
  }
};