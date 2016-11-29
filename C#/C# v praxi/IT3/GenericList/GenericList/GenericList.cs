using System;
using System.Collections;
using System.Collections.Generic;

namespace GenericList
{
    public class GenericList<T> : IEnumerable<T>, IList<T>
    {
        public static int IndexOfNotExist
        {
            get { return -1; }
        }

        private Node firstNode;

        public int Count
        {
            get
            {
                int output = 0;
                Node actualNode = firstNode;

                while (actualNode != null)
                {
                    actualNode = actualNode.NextNode;
                    output++;
                }

                return output;
            }
        }
        public bool IsReadOnly
        {
            get { return false; }
        }
        public T this[int index]
        {
            get
            {
                ValidateIndex(index);
                Node actualNode = firstNode;

                while (index-- != 0)
                {
                    actualNode = actualNode.NextNode;
                }

                return actualNode.Item;
            }
            set
            {
                ValidateIndex(index);
                Node actualNode = firstNode;

                while (index-- != 0)
                {
                    actualNode = actualNode.NextNode;
                }

                actualNode.Item = value;
            }
        }

        public GenericList()
        {

        }

        public GenericList(IEnumerable<T> iEnumerable)
        {
            if (iEnumerable == null)
            {
                throw new ArgumentNullException(nameof(iEnumerable), $"{nameof(iEnumerable)} cannot be null.");
            }

            foreach (T item in iEnumerable)
            {
                Add(item);
            }
        }

        public void Add(T item)
        {
            if (item == null)
            {
                throw new ArgumentNullException(nameof(item), $"Value of {nameof(item)} cannot be null.");
            }

            if (firstNode != null)
            {
                Node newNode = new Node();
                newNode.Item   = item;
                newNode.NextNode = firstNode;

                firstNode = newNode;
            }
            else
            {
                firstNode = new Node();
                firstNode.Item = item;
            }
        }

        public bool Remove(T item)
        {
            if (item == null)
            {
                throw new ArgumentNullException(nameof(item), $"Value of {nameof(item)} cannot be null.");
            }
            else if (firstNode == null)
            {
                return false;
            }

            Node actualNode = firstNode;
            Node previousNode = null;

            while (!EqualityComparer<T>.Default.Equals(actualNode.Item, item))
            {
                previousNode = actualNode;
                actualNode = actualNode.NextNode;

                if (actualNode == null)
                {
                    return false;
                }
            }

            if (previousNode != null)
            {
                previousNode.NextNode = actualNode.NextNode;
            }
            else
            {
                firstNode = actualNode.NextNode;
            }

            return true;
        }

        public void RemoveAt(int index)
        {
            ValidateIndex(index);

            Node actualNode = firstNode;
            Node previousNode = null;

            while (index-- != 0)
            {
                previousNode = actualNode;
                actualNode   = actualNode.NextNode;
            }

            if (previousNode != null)
            {
                previousNode.NextNode = actualNode.NextNode;
            }
            else
            {
                firstNode = actualNode.NextNode;
            }
        }

        public int IndexOf(T item)
        {
            if (firstNode == null)
            {
                return IndexOfNotExist;
            }

            int output = 0;
            Node actualNode = firstNode;

            while (!EqualityComparer<T>.Default.Equals(actualNode.Item, item))
            {
                actualNode = actualNode.NextNode;
                output++;
            }

            return output;
        }

        public void Insert(int index, T item)
        {
            ValidateIndex(index);
            Node actualNode = firstNode;

            while (index-- != 0)
            {
                actualNode = actualNode.NextNode;
            }

            Node newNode     = new Node();
            newNode.Item     = actualNode.Item;
            newNode.NextNode = actualNode.NextNode;

            actualNode.Item     = item;
            actualNode.NextNode = newNode;
        }

        public void Clear()
        {
            firstNode = null;
        }

        public bool Contains(T item)
        {
            if (firstNode == null)
            {
                return false;
            }

            Node actualNode = firstNode;

            while (!EqualityComparer<T>.Default.Equals(actualNode.Item, item))
            {
                actualNode = actualNode.NextNode;

                if (actualNode == null)
                {
                    return false;
                }
            }

            return true;
        }

        public void CopyTo(T[] array, int arrayIndex)
        {
            if (array == null)
            {
                throw new ArgumentNullException(nameof(array), $"Value of {nameof(array)} cannot be null.");
            }
            else if (arrayIndex < 0 || arrayIndex >= array.Length)
            {
                throw new IndexOutOfRangeException($"Value of {nameof(arrayIndex)} must be in range from 0 to {array.Length}");
            }
            else if (array.Length - arrayIndex - Count < 0)
            {
                throw new ArgumentException($"The number of elements in this {nameof(GenericList<T>)} is greater than the available space from arrayIndex to the end of the destination array.");
            }
            
            Node actualNode = firstNode;

            while (actualNode != null)
            {
                array[arrayIndex++] = actualNode.Item;
                actualNode = actualNode.NextNode;
            }
        }

        public IEnumerator<T> GetEnumerator()
        {
            Node actualNode = firstNode;

            while (actualNode != null)
            {
                yield return actualNode.Item;
                actualNode = actualNode.NextNode;
            }
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            Node actualNode = firstNode;

            while (actualNode != null)
            {
                yield return actualNode.Item;
                actualNode = actualNode.NextNode;
            }
        }

        private void ValidateIndex(int index)
        {
            if (index < 0 || index >= Count)
            {
                throw new IndexOutOfRangeException($"Value of {nameof(index)} must be in range from 0 to {Count}");
            }
        }

        private class Node
        {
            public T Item { get; set; }
            public Node NextNode { get; set; }
        }
    }
}
