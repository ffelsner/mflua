print("\n······· mflua_end_program says: 'Hello world!' ·······")


local function _eval(q,offset)
   local qx,qy,xo,yo
   local w 
   w=string.gmatch(q,"[-0-9.]+"); qx,qy=w(),w()
   w=string.gmatch(offset,"[-0-9.]+"); xo,yo=w(),w()
   return string.format("(%s,%s)",qx+xo,qy+yo)
end

local function _eval_tonumber(q,offset)
   local qx,qy,xo,yo
   local w 
   w=string.gmatch(q,"[-0-9.]+"); qx,qy=w(),w()
   w=string.gmatch(offset,"[-0-9.]+"); xo,yo=w(),w()
   return {tonumber(qx+xo),tonumber(qy+yo)}
end


local function _decasteljau(p,c1,c2,q,t)
   local b00,b01,b02,b03 =  {},{},{},{}
   local b10,b11,b12=  {},{},{}
   local b20,b21=  {},{}
   local b30=  {}
   local t = tonumber(t)
   local T=1-t
   --
   -- de Casteljau Algorithm
   -- 
   -- print(string.format("BEZ p=(%s,%s)",p[1],p[2]))
   -- print(string.format("BEZ c1=(%s,%s)",c1[1],c1[2]))
   -- print(string.format("BEZ c2=(%s,%s)",c2[1],c2[2]))
   -- print(string.format("BEZ q=(%s,%s)",q[1],q[2]))

   b00={tonumber(p[1]),tonumber(p[2]) }
   b01={tonumber(c1[1]),tonumber(c1[2]) } 
   b02={tonumber(c2[1]),tonumber(c2[2]) } 
   b03={tonumber(q[1]),tonumber(q[2]) } 

   if t == 1 then -- T = 0
      b10=  {b01[1],b01[2]}
      b11=  {b02[1],b02[2]}
      b12=  {b03[1],b03[2]}
      
      b20=  {b11[1],b11[2]}
      b21=  {b12[1],b12[2]}
      
      b30=  {b21[1],b21[2]}
   elseif t == 0 then -- T = 1
      b10=  {b00[1] ,b00[2] }
      b11=  {b01[1] ,b01[2] }
      b12=  {b02[1] ,b02[2] }
      
      b20=  {b10[1] ,b10[2] }
      b21=  {b11[1] ,b11[2] }
      
      b30=  {b20[1] ,b20[2] }
   else
      b10=  {T*b00[1] + t*b01[1],T*b00[2] + t*b01[2]}
      b11=  {T*b01[1] + t*b02[1],T*b01[2] + t*b02[2]}
      b12=  {T*b02[1] + t*b03[1],T*b02[2] + t*b03[2]}
      
      b20=  {T*b10[1] + t*b11[1],T*b10[2] + t*b11[2]}
      b21=  {T*b11[1] + t*b12[1],T*b11[2] + t*b12[2]}
      
      b30=  {T*b20[1] + t*b21[1],T*b20[2] + t*b21[2]}
   end

   -- b10=  {b00[1] + t*(b01[1]-b00[1]),b00[2] + t*(b01[2]-b00[2])}
   -- b11=  {b01[1] + t*(b02[1]-b01[1]),b01[2] + t*(b02[2]-b01[2])}
   -- b12=  {b02[1] + t*(b03[1]-b02[1]),b02[2] + t*(b03[2]-b02[2])}

   -- b20=  {b10[1] + t*(b11[1]-b10[1]),b10[2] + t*(b11[2]-b10[2])}
   -- b21=  {b11[1] + t*(b12[1]-b11[1]),b11[2] + t*(b12[2]-b11[2])}

   -- b30=  {b20[1] + t*(b21[1]-b20[1]),b20[2] + t*(b21[2]-b20[2])}


   -- p=b00 c1=b01 c2=b02 q=b03 0<= t' <= 1 is C(t')
   -- C(t'=t) is x(t)=b30[1], y(t)=b30[2] 
   -- p=b00 c1=b10 c2=b20 q=b30 0<= t' <= 1 is  C(0<=t'<=t)
   -- p=b30 c1=b21 c2=b12 q=b03 0<= t' <= 1 is  C(t<=t'<=1)
   return b30[1],b30[2],b00,b10,b20,b30,b21,b12,b03

end

local function pixel_map(edges)
   --
   --
   --
   local pixel = {}
   print(edges[1][2],edges[1][3])
   local y = edges[1][1]
   local x_off,y_off = edges[1][2],edges[1][3]
   for row,v in ipairs(y) do 
      pixel[tonumber(v[1])]={}
      local xq,xr=v[2],v[3]
      for j=1,#xr-1 do
	 local xb,xe = xr[j][1],xr[j+1][1]
	 local xsb,xse = xr[j][3],xr[j+1][3]
	 if xsb>0 then 
	    for x=xb,xe do
	       pixel[tonumber(v[1])][x+x_off]=true
	    end
	 end
      end
   end
   return pixel
end

local function _get_contours(char)
   --
   --
   --
   print("BEZ _get_contours")
   local res = ''
   local beziers = char['contour'] or  {}
   local offset = '(0,0)'
   local valid_curves = {}
   local coll_ind = {}
   for i1, bezier in ipairs(beziers) do
      for i, contour in ipairs(bezier) do
	 local path_list = contour['path_list']
	 for j=1 ,#path_list do
	    local path = path_list[j]
	    local p,c1,c2,q = path['p'],path['control1'],path['control2'],path['q']
	    if not(q==nil) then 
	       res = string.format("label(\"i1=%s, i=%s\",0.5(%s+%s));\n",i1,i,q,p)
	       valid_curves[#valid_curves+1] ={p,c1,c2,q,offset,res}
	    end
	 end
      end
   end
   return valid_curves
end


local function _get_envelopes_and_pens(char)
   --
   -- 
   --
   print("BEZ get_envelopes_and_pens")
   local res = ''
   local bezier_octant
   local offsets,path_list,offset_list
   local shifted 
   local p,c1,c2,q,offset,segment
   local pen
   local beziers
   local first_point, last_point 
   local first_point_with_offset={}
   local last_point_with_offset={}
   local knots_list = char['knots'] or {} 
   local knots, knot
   local first_pen = {} 
   local last_pen  ={}
   local knots_set = {}
   local knots_set_1 = {}
   local pen_over_knots = {}

   local valid_curves = {}
   local valid_curves_pen = {}
   local valid_curves_pen_by_offset ={}

   bezier_octant = char['envelope'] or  {}
   char['envelope'] = bezier_octant
   for m=1, #char['envelope']  do ---(#char['envelope']-1) do
      bezier_octant = char['envelope'][m]
      first_point= ''
      last_point = ''
      knots = knots_list[m] or {}
      for i=1, #bezier_octant  do
	 beziers = bezier_octant[i]
	 -- maybe pen ∈ {envelope} ?
	 pen = beziers['pen']
	 offsets = beziers['offsets'] -- ?
	 path_list = beziers['path_list'] or {}
	 offset_list = beziers['offset_list']
	 for j=1,#path_list do
	    path=path_list[j]
	    p,c1,c2,q,offset = path['p'],path['control1'],path['control2'],path['q'],path['offset']  	 
	    for i,v in ipairs(offset_list) do 
	       if v[1] == (0+offset) then 
		  shifted = v[2] 
		  break 
	       end 
	    end 
	    if string.len(first_point) == 0 then
	       first_point = _eval(p,shifted)
	       first_point_with_offset={p,shifted}
	    end
	    if (q == nil) then
	       -- it's a... ?
	       if string.len(last_point) > 0 and not(last_point == _eval(p,shifted)) then 
		  -- DELETE THIS ?
		  res = '1'
		  valid_curves[#valid_curves+1] ={last_point,last_point,_eval(p,shifted),_eval(p,shifted),'(0,0)',res}
		  last_point = _eval(p,shifted)
		  last_point_with_offset={p,shifted}
		  res = ''
	       end
	    else -- not(q == nil)
	       if string.len(last_point) > 0 and not(last_point == _eval(p,shifted)) then 
		  -- DELETE THIS ?
		  res ='2'
		  valid_curves[#valid_curves+1] ={last_point,last_point,_eval(p,shifted),_eval(p,shifted),'(0,0)',res}
		  last_point = _eval(q,shifted)
		  last_point_with_offset={q,shifted}
	       end
	       last_point = _eval(q,shifted)
	       last_point_with_offset={q,shifted}
	       res='3'
	       valid_curves[#valid_curves+1] ={p,c1,c2,q,shifted,res}
	    end -- if (q==nil=
	 end -- for j=1,#path_list do
	 --
	 -- check pen
	 --
	 local coll_ind_pen = {}
	 --knots_set = {} 
         if #knots>0 then 
	    --print("BEZ #knots="..#knots)
	    for k=1,#knots do -- should be this but it's too much slow. and broke s of ccr5  By the way, it must be 	       set for sym.mf .
	       -- a solution is to use #knots when #knots is small
	       -- for _,k in ipairs({1,math.floor(#knots/2)}) do
	       -- for idx,k in ipairs({1,math.floor(#knots/2),1+math.floor(#knots/2),#knots}) do
	       local key =''
	       local key_1 =''
	       local go_on = true
	       local _pen = table.concat(pen)
	       knot = knots[k]
	       p,c1,c2,q,s = knot[1],knot[2],knot[3],knot[4],knot[5]
	       -- try to avoid useless check
	       key = p ..c1 ..c2 ..q ..':'.._pen
	       --print("BEZ key=",k,key)
	       if knots_set[key]~=nil  then 
		  --print("BEZ break")
		  go_on=false
		  --break 
	       else  
		  knots_set[key]=true 
		  go_on=true
	       end
	       io.flush()
	       if go_on == true then
		  res = ''
		  --shift is (0,0) 
		  pen_over_knots[#pen_over_knots+1] = {p,c1,c2,q,'(0,0)',res,pen}
		  local limit_pen = #pen
		  --pen[#pen+1] = pen[1]
		  --local key = ''
		  local pen_c1=nil
		  local _t={}
		  key_1 = p.._pen
		  if knots_set_1[key_1]==nil  then 
		     knots_set_1[key_1]=true
		     for l=1,limit_pen do 
			res ='4'
			--key=key..pen[l]
			valid_curves_pen[#valid_curves_pen+1] ={pen[l],pen_c1,pen_c1,pen[l+1]or pen[1],p,res}
			_t[#_t+1]={pen[l],pen[l+1]or pen[1],res}
		     end
		     if valid_curves_pen_by_offset[p]==nil then 
			valid_curves_pen_by_offset[p]={_t}
		     else
			table.insert(valid_curves_pen_by_offset[p],_t)
		     end
		  end -- knots_set_1[key_1]==nil
	       end -- go_on==true
	    end -- for 
	 end  -- if#knots>0 
	 --print("BEZ the pen end")
      end -- for i=1, #bezier_octant do
      local nr_ok,values 
      if not(last_point == first_point) then 
	 -- DELETE THIS ?
	 res = '5'
	 --valid_curves[#valid_curves+1] ={last_point,last_point,first_point,first_point,'(0,0)',res}
      end 
   end --    for m=1,#char['envelope'] 
   --print("BEZ return")
   return valid_curves,valid_curves_pen,pen_over_knots,valid_curves_pen_by_offset
end

local function _get_beziers_of_pen(pen_over_knots)
   --
   --
   -- 	       
   local  valid_curves_p_bez = {}
   local pen_ellipse = {}
   local mflua_exe = mflua.mflua_exe or './mf' 
   for i,v in ipairs(pen_over_knots) do
      --v = {p,c1,c2,q,'(0,0)',res,pen}
      local shifted, pen = v[1],v[7]
      local delta_offset = '(0,0)'
      --
      -- Uh ... why ?
      -- 
      if #pen==40 then  delta_offset ='(-0.5,-0.5)' end
      local key = table.concat(pen)
      --print("BEZ pen=",key,table.concat(mflua.pen[key]),#pen,shifted)
      if mflua.pen[key] ~=nil then 
        pen_ellipse[shifted] = {mflua.pen[key],delta_offset}
      end
   end
   for k,v in pairs(pen_ellipse) do
      local shift = k
      --print("BEZ shift=",k,shift,mflua.round0(shift))
      local major_axis__minor_axis,theta,tx__ty = v[1][1],v[1][2],v[1][3]
      local delta_offset =  v[2]
      --print("BEZ pen_ellipse = ",k,major_axis__minor_axis,theta,tx__ty)
      -- First time of  major_axis__minor_axis..theta..tx__ty
      if mflua.set_poly_done[major_axis__minor_axis..theta..tx__ty] == nil then
	 local match=string.gmatch(major_axis__minor_axis,"[%d\.]+")
	 local major_axis, minor_axis = match(),match()
	 local mfstring = string.format(
	    "batchmode;\n"..
	       "fill fullcircle xscaled (%s) yscaled (%s)  rotated (%s) shifted %s;\n"..
	       "shipit;\n"..   
	       "bye.\n",   
	    major_axis, minor_axis,theta,tx__ty)
	 mflua.lock("LOCK_ELLIPSE")
	 local file_name = "poly_to_bezier.mf"
	 local temp_file = io.open(file_name,'w')
	 temp_file:write(mfstring)
	 temp_file:close()
	 os.execute(string.format("%s %s",mflua_exe,file_name));
	 --print("BEZ unlock LOCK_ELLIPSE")
	 mflua.unlock("LOCK_ELLIPSE")
	 local curves = dofile('poly_to_bezier.lua')
	 mflua.set_poly_done[major_axis__minor_axis..theta..tx__ty] = curves
	 valid_curves_p_bez[shift] = {}
	 for _,vv in pairs(curves) do
	    local p,c1,c2,q,offset= vv[1],vv[2],vv[3],vv[4],vv[5]
	    offset = _eval(offset,delta_offset)
	    valid_curves_p_bez[shift][#valid_curves_p_bez[shift]+1] = {p,c1,c2,q,offset}
	    --print("BEZ curves are",p,c1,c2,q,offset,shift)
	 end
      else -- already seen
	 local curves =  mflua.set_poly_done[major_axis__minor_axis..theta..tx__ty] 
	 valid_curves_p_bez[shift] = {}
	 for _,vv in pairs(curves) do
	    local p,c1,c2,q,offset= vv[1],vv[2],vv[3],vv[4],vv[5]
	    offset = _eval(offset,delta_offset)
	    valid_curves_p_bez[shift][#valid_curves_p_bez[shift]+1] = {p,c1,c2,q,offset}
	    --print("BEZ curves are",p,c1,c2,q,offset,shift)
	 end
      end -- if _set_poly_done[major_axis__minor_axis..theta..tx__ty] == nil then
   end
   return valid_curves_p_bez
end

local function _remove_envelope_curves_in_pen(valid_curves_e,valid_curves_p_by_offset)
   local curves_e ={}
   local _t={}
   local p_e,c1_e,c2_e,q_e,shifted_e,res_e
   local p,c1,c2,q,shifted,res

   --for k,v in pairs(valid_curves_e) do curves_e[k]=v end
   
   for i, curve_e in pairs(valid_curves_e) do
      _t[i]=true
      p_e,c1_e,c2_e,q_e,shifted_e,res_e = curve_e[1],curve_e[2],curve_e[3],curve_e[4],curve_e[5],curve_e[6]
      local P_e,Q_e = _eval(p_e,shifted_e),_eval(q_e,shifted_e)
      for offset,array_of_pens in pairs(valid_curves_p_by_offset) do
	 --
	 -- We can have more pens for an offset
	 --
	 for l,pen in ipairs(array_of_pens) do
	    local _tt= {}
	    for m,curve in ipairs(pen) do
	       p,q,res = curve[1],curve[2],curve[3]
	       local P,Q = _eval(p,offset),_eval(q,offset)
	       _tt[P]= true;_tt[Q]=true
	    end       
	    --if ((P==p_e)and (Q==q_e)) or ((Q==p_e)and (Q==q_e)) then
	    if _tt[P_e] and _tt[Q_e] then
	       --print("drawoptions(withcolor (1,0,1)  withpen pencircle scaled 1pt);")
	       --print(string.format("draw (%s .. controls %s and %s .. %s) shifted %s;",p_e,c1_e,c2_e,q_e,shifted_e))
	       _t[i]=false
	    end
	    --print("BEZ ---")
	 end
      end
   end
   for i, curve_e in pairs(valid_curves_e) do
      if _t[i] == true then
	 curves_e[#curves_e+1]=curve_e
      end
   end
   return curves_e
end


local function _draw_curves(valid_curves,withdots,withoptions)
   --
   --
   --
   local _t={}
   local with_dots = withdots
   local with_options = withoptions
   if withdots == nil then with_dots=true end
   if withoptions ==nil then  
      with_options = "drawoptions(withcolor (0,0,0)  withpen pencircle scaled 0.1pt);"
   end

   if #valid_curves>0 then
      _t[#_t+1]=with_options.."\n"
      _t[#_t+1]="path p;\n"
   else
      return ''
   end
   for i,bezier in ipairs(valid_curves) do
      local p,c1,c2,q,shifted,res = bezier[1],bezier[2],bezier[3],bezier[4],bezier[5],bezier[6]
      if with_dots then 
	 _t[#_t+1]=string.format("draw %s withpen pencircle scaled 0.2pt shifted %s; ", p,shifted)
	 _t[#_t+1]=string.format("draw %s withpen pencircle scaled 0.2pt shifted %s; ", q,shifted)
      end

      if c1 == nil and c2 == nil then 
	 _t[#_t+1]=string.format("p:=%s -- %s;%% %03d\n",p,q,i)
	 _t[#_t+1]=string.format("draw p shifted %s;%% %03d\n",shifted,i)

      else
	 _t[#_t+1]=string.format("p:=%s .. controls %s and %s .. %s;%% %03d\n", p,c1,c2,q,i)
	 _t[#_t+1]=string.format("draw p shifted %s;%% %03d\n",shifted,i)
      end
   end
   return table.concat(_t)
end


local function _draw_curves_of_pens(valid_curves_p_bez,withdots,withoptions)  
   --
   -- 
   --
   local _t ={}
   local str = ''
   local i=0
   local with_dots = withdots
   local with_options = withoptions
   if withdots == nil then with_dots=true end
   if withoptions ==nil then  
      with_options = "drawoptions(withcolor (1,0,0)  withpen pencircle scaled 0.1pt);"
   end
   _t[#_t+1]= with_options.."\n"
   _t[#_t+1]= "path pp;\n"
   
   for shift, curves in pairs(valid_curves_p_bez) do
      _t[#_t+1]="%% SHIFT="..shift.."\n"
      for _,curve in ipairs(curves) do
	 local p,c1,c2,q,offset = curve[1],curve[2],curve[3],curve[4],curve[5]
	 local shifted = _eval(offset,shift)
	 if with_dots then 
	    _t[#_t+1]=string.format("draw %s withpen pencircle scaled 0.2pt shifted %s; ", p,shifted)
	    _t[#_t+1]=string.format("draw %s withpen pencircle scaled 0.2pt shifted %s; ", q,shifted)
	 end
	 i=i+1
	 if c1 == nil and c2 == nil then 
	    _t[#_t+1]= string.format("pp:=%s .. %s;%% %03d\n",i,p,q)
	    _t[#_t+1]= string.format("draw pp shifted %s;%% %03d\n",shifted,i)
	 else
	    _t[#_t+1]= string.format("pp:=%s .. controls %s and %s .. %s;%% %03d\n",p,c1,c2,q,i)
	    _t[#_t+1]= string.format("draw pp shifted %s;%% %03d\n",shifted ,i)
	 end
      end
   end
   return table.concat(_t)
end

local function _draw_pixels(pixels)
   local res = ''
   res = res .. "drawoptions(withcolor (0.8,0.8,0.8) withpen pencircle scaled 0.01pt);\n" 
   local _t={}
   for y,v in pairs(pixels) do
      --print("BEZ row=",row)
      for x,_ in pairs(v) do
	 --print("BEZ x=",x)
	 --res=res..string.format('drawdot(%s+0.5,%s+0.5);\n',x,y)
	 if pixels[y+1]~=nil then 
	    if pixels[y][x+1]~=nil and pixels[y+1][x]~=nil and pixels[y+1][x+1]~=nil then
	       _t[#_t+1]=string.format("draw (%s,%s) -- (%s,%s) -- (%s,%s+1) -- (%s,%s+1) --cycle;\n",
		  x,y, x+1,y, x+1,y+1, x,y+1)
	    end
	 end
      end
   end
   return res..table.concat(_t)
end



local function _save_as(format,outdir,filename,res)
   if format =='metapost' then
      local f = io.open(outdir..'/'..filename,'w')
      local preamble=''
      local content = "beginfig(1);\n"..res.."\n".."\nendfig;\nend."
      f:write(content)
      f:close()
   end
end


function end_program()
   if mflua.checklock('LOCK_ELLIPSE') then
      dofile("end_program_poly_to_bezier.lua")
      print("BEZ finished end_program_poly_to_bezier")
      return 
   end

   local chartable = mflua.chartable 
   -- mflua.checklock('LOCK1') ?
   local f = mflua.print_specification.outfile1 or nil
   -- some mflua instances cannot have this file open
   if f==nil then return end

   
   local res = ""
   local t = {}
   local tfm;
   --local tfm = dofile('tfm.lua') 
   --print("tfm run:",tfm.run("pen.tfm"))

   f:write("\n%%\\starttext\\setupbodyfont[tt,2pt]\\bf\\stoptext %% comment this line to make an empty pdf \n")
   f:write("\\starttext\n\\setupbodyfont[tt,5pt]\\bf\n")
   --f:write("\\starttext\n\\setupbodyfont[tt,4pt]\\bf\n")
   for k,_ in pairs(chartable) do t[#t+1]=k end
   table.sort(t)
   for i,_ in ipairs(t) do
      local valid_curves_e = {}
      local valid_curves_c = {}
      local valid_curves_p = {}
      local valid_curves_p_by_offset= {}
      local valid_curves_p_bez = {}
      local pixels ={}

      local pen_over_knots = {}
      local valid_curves = {}
      local index = t[i]
      local char= chartable[index]
      -- useful to have, but unused
      -- because edges are stored in
      -- char['pre_res'] by print_edges.lua
      local edges = char['edges']
      local ye_map = {}
      for i,v in ipairs(edges[1][1]) do ye_map[v[1]] = i  end
      char['edges_map'] = ye_map 

      pixels=pixel_map(edges)

      -- get contours
      valid_curves_c =  _get_contours(char)
      --for i,curve in ipairs(valid_curves_c) do local p,c1,c2,q,offset,res = curve[1],curve[2],curve[3],curve[4],curve[5],curve[6] print(p,c1,c2,q,offset,res)  end

      -- get envelopes
      valid_curves_e,valid_curves_p,pen_over_knots,valid_curves_p_by_offset = _get_envelopes_and_pens(char)
      --for i,curve in ipairs(valid_curves_e) do local p,c1,c2,q,offset,res = curve[1],curve[2],curve[3],curve[4],curve[5],curve[6] print(p,c1,c2,q,offset,res)  end

      --for i,curve in ipairs(valid_curves_p) do local p,c1,c2,q,offset,res = curve[1],curve[2],curve[3],curve[4],curve[5],curve[6] print(p,c1,c2,q,offset,res)  end
      --valid_curves_p_bez = _get_beziers_of_pen(valid_curves_p)
      valid_curves_p_bez = _get_beziers_of_pen(pen_over_knots)


      valid_curves_e = 
	 _remove_envelope_curves_in_pen(valid_curves_e,valid_curves_p_by_offset)




      print("BEZ DRAW")

      local res_pens = _draw_curves(valid_curves_p,true,
				    "drawoptions(withcolor (0,1,1)  withpen pencircle scaled 0.01pt);")    

      --f:write("\\startMPpage%%%% BEGIN EDGES\n")
      --res = "%% char " .. index .."\n"
      --local pre_res = char['pre_res'] or ""
      --res = res .. pre_res .."\n"
      --local v_res = char['res'] or ""
      --res = res .. v_res .."\n"
      --local post_res = char['post_res'] or ""
      --res = res .. post_res .."\n"
      --res = res .. res_pens
      --f:write(res)
      --f:write("\n\\stopMPpage%%%% END EDGES\n")
      --
      res = ''
      res = res .. _draw_pixels(pixels)
      res = res .. _draw_curves(valid_curves_c,false,
				"drawoptions(withcolor (0,0,0)  withpen pencircle scaled 0.01pt);")    
      res = res .. _draw_curves(valid_curves_e,true,
				"drawoptions(withcolor (0,0,1)  withpen pencircle scaled 0.01pt);")      
      res = res .. _draw_curves(pen_over_knots,true,
				"drawoptions(withcolor (0.5,0.2,0)  withpen pencircle scaled 0.1pt);")  
      res = res .. res_pens
      res = res .. _draw_curves_of_pens(valid_curves_p_bez,true,
					"drawoptions(withcolor (1,0,0)  withpen pencircle scaled 0.01pt);")  


      f:write("\\startMPpage%%%% BEGIN CURVES\n")
      f:write(res)
      f:write("\\stopMPpage%%%% END CURVES\n")

      --
      print("BEZ export in mp/"..string.format("char_%03d.mp",index))
      res = _draw_curves(valid_curves_c,false)  
      res = res .. _draw_curves(valid_curves_e,false)  
      res = res  .._draw_curves(valid_curves_p,false)  
      res = res .. _draw_curves_of_pens(valid_curves_p_bez,false)  
      _save_as('metapost','mp',string.format("char_%03d.mp",index),res) ;
   end
   f:write("\n\\stoptext\n")
   f:close()
end

end_program()


